# https://leetcode.com/problems/rotting-oranges
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows,cols=len(grid),len(grid[0])
        fresh_oranges=0
        queue=deque()
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==2:
                    queue.append((r,c))
                elif grid[r][c]==1:
                    fresh_oranges+=1
        directions=[(-1,0),(0,1),(1,0),(0,-1)]
        time_taken=-1
        queue.append((-1,-1))
        while queue:
            row,col=queue.popleft()
            if row==-1:
                time_taken+=1
                if queue:
                    queue.append((-1,-1))
            else:
                for d in directions:
                    n_row,n_col=row+d[0],col+d[1]
                    if rows>n_row>=0 and cols>n_col>=0:
                        if grid[n_row][n_col]==1:
                            grid[n_row][n_col]=2
                            fresh_oranges-=1
                            queue.append((n_row,n_col))
        return time_taken if fresh_oranges==0 else -1
                        