#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> result;
    void printAllParenthesis(int openStack,int closeStack,string s)
    {
        if(openStack==0 && closeStack==0)
            result.push_back(s);
        if(openStack>0)
            printAllParenthesis(openStack-1,closeStack+1,s+"(");
        if(closeStack>0)
            printAllParenthesis(openStack,closeStack-1,s+")");
    }
    vector<string> generateParenthesis(int n) {
        if(n)
            printAllParenthesis(n,0,"");
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/generate-parentheses/
    return 0;
}