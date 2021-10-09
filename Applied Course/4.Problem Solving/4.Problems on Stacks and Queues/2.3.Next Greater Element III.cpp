#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        string A=to_string(n);
        if(next_permutation(A.begin(),A.end()))
            return stoll(A)>INT_MAX?-1:stoi(A);
        else 
            return -1;
    }
};
int main()
{
    // https://leetcode.com/problems/next-greater-element-iii/
    return 0;
}