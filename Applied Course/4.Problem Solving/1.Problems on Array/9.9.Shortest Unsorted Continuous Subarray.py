# https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
# Logic-1 - Time Limit Exceeded
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        start,end=len(nums),0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                if nums[i]>nums[j]:
                    start=min(start,i)
                    end=max(end,j)
        if end-1<0:
            return 0
        return end-start+1
# Logic-2
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        start,end=len(nums),0
        snums=nums[:]
        snums.sort()
        for i in range(len(nums)):
            if snums[i]!=nums[i]:
                start=min(start,i)
                end=max(end,i)
        if end-start>=0:
            return end-start+1
        return 0
# Logic-3
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        stack=[]
        start,end=len(nums),0
        for i in range(len(nums)):
            while stack and nums[stack[-1]]>nums[i]:
                start=min(start,stack.pop())
            stack.append(i)
        stack=[]
        for i in range(len(nums)-1,-1,-1):
            while stack and nums[stack[-1]]<nums[i]:
                end=max(end,stack.pop())
            stack.append(i)
        if end-start>=0:
            return end-start+1
        return 0