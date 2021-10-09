# https://leetcode.com/problems/sort-array-by-parity/
# Logic-1
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        return [i for i in A if i%2==0]+[i for i in A if i%2!=0]
# Logic-2
class Solution:
    def sortArrayByParity(self, A: List[int]) -> List[int]:
        i=0
        j=len(A)-1
        while(i<j):
            if A[i]%2!=0:
                A[i],A[j]=A[j],A[i]
                j-=1
            else:
                i+=1
        return A