# https://leetcode.com/problems/set-matrix-zeroes/
# Logic-1
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        n = len(matrix[0])
        rows = set()
        columns = set()
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    rows.add(i)
                    columns.add(j)
        for i in range(m):
            for j in range(n):
                if i in rows or j in columns:
                    matrix[i][j] =0
        return matrix
# Logic-2
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row_flag, col_flag = False, False
        m = len(matrix)
        n = len(matrix[0])
        #Traverse the 
        for i in range(m):
            for j in range(n):
                if i==0 and matrix[i][j] == 0:
                    row_flag = True
                if j == 0 and matrix[i][j] == 0:
                    col_flag = True
                if matrix[i][j] == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if row_flag == True:
            for i in range(n):
                matrix[0][i] = 0
        if col_flag:
            for j in range(m):
                matrix[j][0] = 0
        return matrix