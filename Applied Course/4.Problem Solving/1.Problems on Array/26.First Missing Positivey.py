# https://leetcode.com/problems/first-missing-positive
# Logic-1
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        result=1
        nums.sort()
        for i in range(len(nums)):
            if nums[i]==result:
                result+=1
        return result
# Logic-2
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if 1 not in nums:
            return 1
        n=len(nums)
        for i in range(n):
            if nums[i]<=0 or nums[i]>n:
                nums[i]=1
        for i in range(n):
            val=abs(nums[i])
            if val==n:
                nums[0]=-abs(nums[0])
            else:
                nums[val]=-abs(nums[val])
        for i in range(1,n):
            if nums[i]>0:
                return i
        if nums[0]>0:
            return n
        return n+1