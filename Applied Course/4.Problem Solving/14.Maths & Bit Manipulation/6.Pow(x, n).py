# https://leetcode.com/problems/powx-n/
# Logic-1
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            x=1/x
            n=-n
        result=1
        for i in range(n):
            result*=x
        return result
# Logic-2
class Solution:
    def fastPow(self,x,n):
        if n==0:
            return 1.0
        A=self.fastPow(x,n//2)
        if n%2==0:
            return A*A
        else:
            return A*A*x
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            x=1/x
            n=-n
        return self.fastPow(x,n)
# Logic-3
class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n<0:
            x=1/x
            n=-n
        result=1
        current_product=x
        i=n
        while i:
            if i%2==1:
                result*=current_product
            current_product*=current_product
            i//=2
        return result