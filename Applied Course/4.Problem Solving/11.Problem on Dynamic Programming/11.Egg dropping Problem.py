# Logic-1 recursive Approach
import sys
def eggDropsRecursion(eggs,floor):
    if floor==0 or floor==1:
        return floor
    if eggs==1:
        return floor
    minvalue=sys.maxsize
    
    for i in range(1,floor+1):
        temp=max(eggDropsRecursion(eggs-1,i-1),eggDropsRecursion(eggs,floor-i))
        if temp<minvalue:
            minvalue=temp
            
    return minvalue+1

if __name__=='__main__':
    print(eggDropsRecursion(2,10))
    
# Logic-2 dynamic Programming Appraoch
import sys
def eggDrops(eggs,floor):
    dp=[[0 for x in range(floor+1)] for x in range(eggs+1)]
    for i in range(1,eggs+1):
        dp[i][1]=1
    for i in range(1,floor+1):
        dp[1][i]=i
    
    for i in range(2,eggs+1):
        for j in range(2,floor+1):
            dp[i][j]=sys.maxsize
            for k in range(1,j+1):
                temp=1+max(dp[i-1][k-1],dp[i][j-k])
                dp[i][j]=min(temp,dp[i][j])
        
    return dp[eggs][floor]
if __name__=='__main__':
    print(eggDropsRecursion(2,10))
