# https://leetcode.com/problems/move-zeroes/
# Logic-1
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        result=[]
        for num in nums:
            if num!=0:
                result.append(num)
        for num in nums:
            if num==0:
                result.append(num)
        for i in range(len(nums)):
            nums[i]=result[i]
# Logic-2
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n=len(nums)
        last_non_zero_index=0
        for i in range(n):
            if nums[i]!=0:
                nums[last_non_zero_index]=nums[i]
                last_non_zero_index+=1
        for i in range(last_non_zero_index,n):
            nums[i]=0