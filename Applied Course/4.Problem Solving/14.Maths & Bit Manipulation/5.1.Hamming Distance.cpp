#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n=x^y;
        int count=0;
        while(n>0)
        {
            n&=n-1;
            count+=1;
        }
        return count;
    }
};
int main()
{
    // https://leetcode.com/problems/hamming-distance/
    return 0;
}