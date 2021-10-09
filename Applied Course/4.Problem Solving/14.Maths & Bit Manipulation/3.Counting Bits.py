# https://leetcode.com/problems/counting-bits/
# Logic-1
class Solution:
    def countBits(self, num: int) -> List[int]:
        def countOnes(n):
            count=0
            while n>0:
                n&=n-1
                count+=1
            return count
        return [countOnes(i) for i in range(num+1)]
# Logic-2
class Solution:
    def countBits(self, num: int) -> List[int]:
        result=[0 for i in range(num+1)]
        for i in range(1,num+1):
            result[i]=result[i//2]+(i%2)
        return result
# Logic-3
class Solution:
    def countBits(self, num: int) -> List[int]:
        result=[0 for i in range(num+1)]
        for i in range(1,num+1):
            result[i]=result[i & (i-1)]+1
        return result