# https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        rows=len(grid)
        cols=len(grid[0])
        i,j=rows-1,0
        count=0
        while i>=0 and j<cols:
            if grid[i][j]<0:
                count+=(cols-j)
                i-=1
            else:
                j+=1
        return count