#include<bits/stdc++.h>
using namespace std;
// Logic-1  T(n)=O(n) S(n)=n Using Stack
class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> stk;
        stk.push(S[0]);
        for(int i=1;i<S.length();i++)
        {
            if(stk.size() && stk.top()==S[i])
                stk.pop();
            else
                stk.push(S[i]);
        }
        S.clear();
        while(stk.size())
        {
            S.insert(0,1,stk.top());
            stk.pop();
        }
        return S;
    }
};
// Logic-2 T(n)=O(n) S(n)=O(1) Using Recursion
class Solution {
public:
    string removeDuplicates(string S) {
        for(int i=1;i<S.length();i++)
            if(S[i]==S[i-1])
                return removeDuplicates(S.substr(0,i-1)+S.substr(i+1));
        return S;
    }
};
// Logic-3 T(n)=O(n) S(n)=O(1) Using Fast and Slow Pointer
class Solution {
public:
    string removeDuplicates(string S) {
        int slow=0;
        for(int fast=0;fast<S.length();fast++)
        {
            if(slow==0 || S[slow-1]!=S[fast])
                S[slow++]=S[fast];
            else
                slow--;
        }
        return S.substr(0,slow);
    }
};
int main()
{
    // https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
    return 0;
}