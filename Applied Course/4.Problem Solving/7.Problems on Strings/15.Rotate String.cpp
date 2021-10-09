#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length()!=B.length())
            return false;
        string temp=A+A;
        size_t found=temp.find(B);
        if(found!=string::npos)
            return true;
        return false;
    }
};
int main()
{
    // https://leetcode.com/problems/rotate-string/
    return 0;
}