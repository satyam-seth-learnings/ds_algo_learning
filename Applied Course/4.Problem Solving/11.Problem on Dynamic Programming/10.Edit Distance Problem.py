# https://leetcode.com/problems/edit-distance
# Logic-1 DP
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        x = len(word1) + 1 
        y = len(word2) + 1 

        A = [[-1 for i in range(x)] for j in range(y)]
        for i in range(x):
            A[0][i] = i

        for j in range(y):
            A[j][0] = j

        for i in range(1, y):
            for j in range(1, x):
                if word1[j- 1] == word2[i - 1]:
                    A[i][j] = A[i - 1][j - 1]
                else:
                    A[i][j] = min(
                            A[i - 1][j] + 1,
                            A[i][j - 1] + 1,
                            A[i - 1][j - 1] + 1
                            )
        return A[y - 1][x - 1]
# Logic-2 Recursion
def minDistance(s1,m,s2,n):
    if m==0:
        return m
    if n==0:
        return n
    
    if s1[m-1]==s2[n-1]:
        cost=0
    else:
        cost=1
        
    return min(minDistace(s1,m-1,s2,n)+1
               ,minDistace(s1,m,s2,n-1)+1,
               minDistace(s1,m-1,s2,n-1)+cost)