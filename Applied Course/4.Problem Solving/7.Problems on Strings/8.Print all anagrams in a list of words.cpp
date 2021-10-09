#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mymap;
        int n=strs.size();
        string temp;
        for(int i=0;i<n;i++)
        {
            temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mymap[strs[i]].push_back(temp);
        }
        vector<vector<string>> result;
        for(auto itr=mymap.begin();itr!=mymap.end();itr++)
            result.push_back(itr->second);
        return result;
    
};
int main()
{
    // https://www.youtube.com/watch?v=0I6IL3TnIZs
    // https://leetcode.com/problems/group-anagrams
    return 0;
}