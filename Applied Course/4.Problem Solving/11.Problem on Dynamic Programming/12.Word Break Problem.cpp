#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        unordered_set<string> dict;
        for(auto word:wordDict)
            dict.insert(word);
        for(int i=n-1;i>=0;i--)
        {
            string word;
            for(int j=i;j<n;j++)
            {
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end() && dp[j+1])
                        dp[i]=1;
            }
        }
        return dp[0];
    }
};
int main()
{
    // https://leetcode.com/problems/word-break
    return 0;
}