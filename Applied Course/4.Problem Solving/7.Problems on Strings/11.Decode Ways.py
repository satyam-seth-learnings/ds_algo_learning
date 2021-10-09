# https://leetcode.com/problems/decode-ways/
# Logic-1
class Solution:
    def recurDecoding(self,index,s):
        if index==len(s):
            return 1
        if s[index]=='0':
            return 0
        if index==len(s)-1:
            return 1
        return self.recurDecoding(index+1,s)+(self.recurDecoding(index+2,s) if (int(s[index:index+2])<=26) else 0)
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        return self.recurDecoding(0,s)
# Logic-2
class Solution:
    def __init__(self):
        self.hash={}
    def recurDecoding(self,index,s):
        if index==len(s):
            return 1
        if s[index]=='0':
            return 0
        if index==len(s)-1:
            return 1
        if index in self.hash:
            return self.hash[index]
        result=self.recurDecoding(index+1,s)+(self.recurDecoding(index+2,s) if (int(s[index:index+2])<=26) else 0)
        self.hash[index]=result
        return result
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        return self.recurDecoding(0,s)