#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;
        long sum=0;
        while(n>0)
        {
            int r=n%10;
            sum=sum*10+r;
            n/=10;
        }
        if(x==sum)
            return true;
        return false;
    }
};
int main()
{
    // https://leetcode.com/problems/palindrome-number/
    return 0;
}