# https://leetcode.com/problems/wiggle-sort/
# Logic-1
class Solution:
    def wiggleSort(self,nums):
        nums.sort()
        for i in range(1,len(nums)-1,2):
            nums[i],nums[i+1]=nums[i+1],nums[i]
        return nums
# Logic-2
class Solution:
    def wiggleSort(self,nums):
        for i in range(1,len(nums),2):
            if i>0 and nums[i]<nums[i-1]:
               nums[i],nums[i-1]=nums[i-1],nums[i]
            if i<len(nums)-1 and nums[i]<nums[i+1]:
               nums[i],nums[i+1]=nums[i+1],nums[i]
        return nums