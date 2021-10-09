# https://leetcode.com/problems/happy-number
class Solution:
    def isHappy(self, n: int) -> bool:
        def get_next(n):
            total=0
            while n>0:
                n,digit=divmod(n,10)
                total+=digit**2
            return total
        slow_ptr=n
        fast_ptr=get_next(n)
        while fast_ptr!=1 and fast_ptr!=slow_ptr:
            slow_ptr=get_next(slow_ptr)
            fast_ptr=get_next(get_next(fast_ptr))
        return fast_ptr==1