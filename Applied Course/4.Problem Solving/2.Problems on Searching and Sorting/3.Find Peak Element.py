# https://leetcode.com/problems/find-peak-element/
# https://leetcode.com/problems/peak-index-in-a-mountain-array
# Logic-1
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        for i in range(len(nums)-1):
            if nums[i]>nums[i+1]:
                return i
        return len(nums)-1
# Logic-2
class Solution:
    def binarySeacrh(self,nums,start,end,n):
        mid=(start+end)//2
        if((mid==0 or nums[mid-1]<nums[mid]) and (mid==n-1 or nums[mid+1]<nums[mid])):
            return mid
        elif(mid>0 and nums[mid-1]>nums[mid]):
            return self.binarySeacrh(nums,start,mid-1,n)
        return self.binarySeacrh(nums,mid+1,end,n)
    def findPeakElement(self, nums: List[int]) -> int:
        return self.binarySeacrh(nums,0,len(nums)-1,len(nums))
# Logic-3
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        start=0
        end=len(nums)-1
        while start<end:
            mid=(start+end)//2
            if nums[mid]>nums[mid+1]:
                end=mid
            else:
                start=mid+1
        return start