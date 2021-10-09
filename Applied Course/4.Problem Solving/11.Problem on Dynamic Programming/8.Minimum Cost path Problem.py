# Logic-1 recursive approach
import sys
def minCost(arr,m,n):
    if m==0 and n==0:
        return arr[m][n]
    elif m<0 or n<0:
        return sys.maxsize
    else:
        return arr[m][n]+min(minCost(arr,m-1,n),
                             minCost(arr,m,n-1))
if __name__=='__main__':
    cost= [ [1, 2, 3], 
            [4, 8, 2], 
            [1, 5, 3] ] 
    print(minCost(cost, 2, 2))
    
    
# Logic-2 dynamic Programming Approach
def minCost(arr,m,n):
    dp=[[0 for x in range(m+1)] for x in range(n+1)]
    dp[0][0]=arr[0][0]
    for i in range(1,m+1):
        dp[i][0]=dp[i-1][0]+arr[i][0]
        
    for i in range(1,n+1):
        dp[0][i]=dp[0][i-1]+arr[0][i]
        
    for i in range(1,m+1):
        for j in range(1,n+1):
            dp[i][j]=arr[i][j]+min(dp[i-1][j],dp[i][j-1])
    return dp[m][n]
if __name__=='__main__':
    cost= [ [1, 2, 3], 
            [4, 8, 2], 
            [1, 5, 3] ] 
    print(minCost(cost, 2, 2))

