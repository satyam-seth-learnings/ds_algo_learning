# Logic-1 recursion Solution
import sys
def minCoinChange(arr,amt,length):
    if amt == 0:
        return 0
    res = sys.maxsize
    for i in range(length):
        if arr[i]<=amt:
            temp=minCoinChange(arr,amt-arr[i],length)
            
            if temp+1<res:
                res=temp+1
    return res

if __name__=='__main__':
    arr = [1, 2, 3] 
    m = len(arr) 
    print(minCoinChange(arr, 15, m))


# Logic-2 bottom up approach
import sys
def minCoinChangeDP(arr,amt,m):
    temp=0
    dp=[0 for i in range(amt+1)]
    for i in range(1,amt+1):
        dp[i]=sys.maxsize
    for i in range(1,amt+1):
        for j in range(m):
            if arr[j]<=i:
                temp=dp[i-arr[j]]
            if temp+1<dp[i]:
                dp[i]=temp+1
    return dp[amt]
if __name__=='__main__':
    arr = [1, 2, 3] 
    m = len(arr) 
    print(minCoinChangeDP(arr, 15, m))
