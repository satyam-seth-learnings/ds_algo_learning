#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength=1;
        int low,high;
        int start=0;
        int len=s.length();
        string res="";
        for(int i=1;i<len;i++)
        {
            low=i-1;
            high=i;
            while(low>=0 && high<len && s[low]==s[high])
            {
                if(high-low+1>maxlength)
                {
                    start=low;
                    maxlength=high-low+1;
                }
                low--;
                high++;
            }
            low=i-1;
            high=i+1;
            while(low>=0 && high<len && s[low]==s[high])
            {
                if(high-low+1>maxlength)
                {
                    start=low;
                    maxlength=high-low+1;
                }
                low--;
                high++;
            }
        }
        for(int j=start;j<=start+maxlength-1;j++)
            res=res+s[j];
        return res;
    }
};
int main()
{
    // https://leetcode.com/problems/longest-palindromic-substring
    return 0;
}