#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_next(int n)
    {
        int total=0;
        while(n>0)
        {
            int digit=n%10;
            n=n/10;
            total+=digit*digit;
        }
        return total;
    }
    bool isHappy(int n) {
        int slow_ptr=n;
        int fast_ptr=get_next(n);
        while(fast_ptr!=1 && fast_ptr!=slow_ptr)
        {
            slow_ptr=get_next(slow_ptr);
            fast_ptr=get_next(get_next(fast_ptr));
        }
        return fast_ptr==1;
    }
};
int main()
{
    // https://leetcode.com/problems/happy-number/
    return 0;
}