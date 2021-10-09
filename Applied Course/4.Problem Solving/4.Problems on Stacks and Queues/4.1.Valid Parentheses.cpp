#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stk.push(s[i]);
            else if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(stk.empty())
                    return false;
                char ch=stk.top();
                if((s[i]==')' && ch=='(') || (s[i]=='}' && ch=='{') || (s[i]==']' && ch=='['))
                    stk.pop();
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};
int main()
{
    // https://leetcode.com/problems/valid-parentheses/
    return 0;
}