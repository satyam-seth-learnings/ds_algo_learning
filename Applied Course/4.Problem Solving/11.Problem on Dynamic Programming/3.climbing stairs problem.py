# https://leetcode.com/problems/climbing-stairs
# Logic-1 DP
class Solution:
    def climbStairs(self, n: int) -> int:
        if(n==1):
            return 1
        dp=[0 for i in range(n+1)]
        dp[1]=1
        dp[2]=2
        for i in range(3,n+1):
            dp[i]=dp[i-1]+dp[i-2]
        return dp[n]
# Logic-2 Recursion
def climb_stairs(i,n):
    if i>n:
        return 0
    if i==n:
        return 1
    return climb_stairs(i+1,n)+climb_stairs(i+2,n)