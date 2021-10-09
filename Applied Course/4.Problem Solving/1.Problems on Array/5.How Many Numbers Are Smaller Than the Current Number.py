# https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
# Logic-1
class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        count={}
        for i,v in enumerate(sorted(nums)):
            if v not in count:
                count[v]=i
        return [count[v] for v in nums]
# Logic-2
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        count=[0]*101
        for val in nums:
            count[val]+=1
        for i in range(1,101):
            count[i]+=count[i-1]
        result=[0]*len(nums)
        for i,val in enumerate(nums):
            if val>0:
                result[i]=count[val-1]
        return result