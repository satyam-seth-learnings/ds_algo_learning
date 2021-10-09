# https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone={
            '2':['a','b','c'],
            '3':['d','e','f'],
            '4':['g','h','i'],
            '5':['j','k','l'],
            '6':['m','n','o'],
            '7':['p','q','r','s'],
            '8':['t','u','v'],
            '9':['w','x','y','z']
        }
        def recursion(combination,digits):
            if len(digits)==0:
                result.append(combination)
            else:
                for char in phone[digits[0]]:
                    recursion(combination+char,digits[1:])
        result=[]
        if len(digits):
            recursion("",digits)
        return result