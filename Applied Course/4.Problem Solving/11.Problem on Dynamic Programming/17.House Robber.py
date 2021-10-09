# https://leetcode.com/problems/house-robber/
# Logic-1 Recursion T(n)=O(2^n)
class Solution:
    def maximize_loot(self,nums,start,end):
        if start>end:
            return 0
        if start==end:
            return nums[start]
        if start+1==end:
            return max(nums[start],nums[end])
        return max(nums[start]+self.maximize_loot(nums,start+2,end),self.maximize_loot(nums,start+1,end))
    
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        return self.maximize_loot(nums,0,n-1)

# Logic-2 DP T(n)=O(n)
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        if n==2:
            return max(nums[0],nums[1])
        dp=[0]*n
        dp[0]=nums[0]
        dp[1]=max(nums[0],nums[1])
        for i in range(2,n):
            dp[i]=max(nums[i]+dp[i-2],dp[i-1])
        return dp[n-1]

# Logic-3 S(n)=O(1)
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==0:
            return 0
        if n==1:
            return nums[0]
        if n==2:
            return max(nums[0],nums[1])
        value1=nums[0]
        value2=max(nums[0],nums[1])
        for i in range(2,n):
            max_value=max(nums[i]+value1,value2)
            value1=value2
            value2=max_value
        return max_value