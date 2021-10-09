#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        unordered_map<string,int> mp;
        for(int i=0;i<list1.size();i++)
            mp[list1[i]]=i;
        int min=list1.size()+list2.size();
        for(int i=0;i<list2.size();i++)
            if(mp.count(list2[i])!=0)
                if(mp[list2[i]]+i<min)
                {
                     min = mp[list2[i]]+i;
                     ans.clear();
                     ans.push_back(list2[i]);
                }
                 else 
                     if(mp[list2[i]]+i==min)
                        ans.push_back(list2[i]);
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/minimum-index-sum-of-two-lists/
    return 0;
}