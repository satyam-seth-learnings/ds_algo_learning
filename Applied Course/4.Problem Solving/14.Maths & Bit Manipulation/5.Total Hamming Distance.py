# https://leetcode.com/problems/total-hamming-distance
# Logic-1
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        def count1bits(n):
            count=0
            while n>0:
                n&=n-1
                count+=1
            return count
        result=0
        for i in range(len(nums)-1):
            for j in range(i+1,len(nums)):
                result+=count1bits(nums[i]^nums[j])
        return result
# Logic-2
class Solution:
    def totalHammingDistance(self, nums: List[int]) -> int:
        n=len(nums)
        result=0
        for i in range(32):
            count=0
            for j in range(n):
                if nums[j]&(1<<i):
                    count+=1
            result+=(count*(n-count))
        return result;