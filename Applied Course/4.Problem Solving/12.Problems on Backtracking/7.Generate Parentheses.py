# https://leetcode.com/problems/generate-parentheses/
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def printAllParenthesis(openStack,closeStack,string):
            if openStack==0 and closeStack==0:
                result.append(string)
            if openStack>0:
                printAllParenthesis(openStack-1,closeStack+1,string+"(")
            if closeStack>0:
                printAllParenthesis(openStack,closeStack-1,string+")")
        result=[]
        if n:
            printAllParenthesis(n,0,"");
        return result