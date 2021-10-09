#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length() || s.length()==0 || t.length()==0)
            return "";
        unordered_map<char,int> need,have;
        int needcount=0,havecount=0;
        int starting=0;
        int mini=INT_MAX;
        for(auto x:t)
            need[x]++;
        needcount=need.size();
        int i=0;
        int j=0;
        for(int j=0;j<s.length();j++)
        {
            have[s[j]]++;
            if(need.find(s[j])!=need.end())
                if(have[s[j]]==need[s[j]])
                    havecount++;
            while(havecount==needcount)
            { 
                if(mini>j-i+1)
                {
                    mini=j-i+1;
                    starting=i;
                }
                if(have.find(s[i])!=have.end())
                {  
                    have[s[i]]--;
                    if(need.find(s[i])!=need.end())
                       if(have[s[i]]<need[s[i]])
                           havecount--;
                    if(have[s[i]]==0)
                        have.erase(s[i]);
                    i++;
                }
            }
        }
        if(mini==INT_MAX)
            return "";
        else
            return s.substr(starting,mini);
      }
};
int main()
{
    // https://leetcode.com/problems/minimum-window-substring
    return 0;
}