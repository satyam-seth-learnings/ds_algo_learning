# Logic-1 recursive approach
def fillNumberWays(n):
    if n==0 or n==1 or n==2 or n==3:
        return 1
    return fillNumberWays(n-1)+fillNumberWays(n-4)

if __name__=='__main__':
    n=5
    print(fillNumberWays(n))
    
# Logic-2 dynamic Programming Approach
def fillNumberWays_dynamic(n):
    dp=[0]*(n+1)
    dp[0],dp[1],dp[2],dp[3]=1,1,1,1
    for i in range(4,n+1):
        dp[i]=dp[i-1]+dp[i-4]
    return dp[n]

if __name__=='__main__':
    n=5
    print(fillNumberWays_dynamic(n))
