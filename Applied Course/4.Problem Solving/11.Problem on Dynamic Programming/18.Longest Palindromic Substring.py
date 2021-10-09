# https://leetcode.com/problems/longest-palindromic-substring/
# Logic-1
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        max_len=0
        result=""
        dp=[[0]*n for i in range(n)]
        for i in range(n):
            dp[i][i]=1
            result=s[i]
            max_len=1
        for i in range(n-1):
            if s[i]==s[i+1]:
                dp[i][i+1]=1
                result=s[i:i+2]
                max_len=2
        for j in range(2,n):
            for i in range(0,j-1):
                if s[i]==s[j] and dp[i+1][j-1]:
                    dp[i][j]=1
                    if max_len<j-i+1:
                        result=s[i:j+1]
                        max_len=j-i+1
        return result

# Logic-2
class Solution:
    def expendAroundCenter(self,left,right,n,max_len,s,result):
        while left>=0 and right<n and s[left]==s[right]:
            if right-left+1>max_len:
                result=s[left:left+(right-left+1)]
                max_len=right-left+1
            left-=1
            right+=1
        return result,max_len
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        if n==0 or n==1:
            return s
        max_len=1
        result=s[0]
        for i in range(1,n):
            result,max_len=self.expendAroundCenter(i-1,i,n,max_len,s,result)
            result,max_len=self.expendAroundCenter(i-1,i+1,n,max_len,s,result)
        return result