#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0)
        {
            count+=n&1;
            n>>=1;
        }
        return count;
    }
};
// Logic-2
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0)
        {
            n=n&n-1;
            count++;
        }
        return count;
    }
};
int main()
{
    // https://leetcode.com/problems/number-of-1-bits/
    return 0;
}