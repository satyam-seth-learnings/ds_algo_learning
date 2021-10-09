#include<bits/stdc++.h>
using namespace std;
// Logic-1 Two Pointer
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int l=0,h=n-1;
        while(l<h)
        {
            while(l<h && !(isalnum(s[l])))
                l++;
            while(l<h && !(isalnum(s[h])))
                h--;
            if(tolower(s[l])!=tolower(s[h]))
                return false;
            l++;
            h--;
        }
        return true;
    }
};
// Logic-2 Aux String
class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto c:s)
            if(isalnum(c))
               temp+=tolower(c);
        int n=temp.length();
        int l=0,h=n-1;
        while(l<h)
        {
            if(temp[l]!=temp[h])
                return false;
            l++;
            h--;
        }
        return true;
    }
};
// Logic-3 Use Stack
class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> stk;
        for(auto c:s)
            if(isalnum(c))
                stk.push(tolower(c));
        for(auto c:s)
        {
            if(isalnum(c))
            {
                if(tolower(c)==stk.top())
                    stk.pop();
                else
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    // https://leetcode.com/problems/valid-palindrome/
    return 0;
}