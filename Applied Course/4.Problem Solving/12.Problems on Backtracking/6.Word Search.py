# https://leetcode.com/problems/word-search/
class Solution:
    def pathExist(self,row,col,word):
        if len(word)==0:
            return True
        if row<0 or col<0 or row==self.ROWS or col==self.COLS or self.board[row][col]!=word[0]:
            return False
        ret=False
        self.board[row][col]='@'
        for rowoffset,coloffset in [(0,1),(1,0),(-1,0),(0,-1)]:
            ret=self.pathExist(row+rowoffset,col+coloffset,word[1:])
            if ret:
                break
        self.board[row][col]=word[0]
        return ret
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.ROWS=len(board)
        self.COLS=len(board[0])
        self.board=board
        for i in range(self.ROWS):
            for j in range(self.COLS):
                if self.pathExist(i,j,word):
                    return True
        return False