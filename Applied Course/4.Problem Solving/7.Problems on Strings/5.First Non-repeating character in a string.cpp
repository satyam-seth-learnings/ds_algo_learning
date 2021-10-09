#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(auto ch:s)
            m[ch]++;
        for(int i=0;i<s.size();i++)
            if(m[s[i]]==1)
                return i;
        return -1;
    }
};
// Logic-2
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> temp(26,0);
        for(int i=0;i<s.size();i++)
            temp[s[i]-'a']++;
        for(int i=0;i<s.size();i++)
            if(temp[s[i]-'a']==1) 
                return i;
        return -1;
    }
};
int main()
{
    // https://leetcode.com/problems/first-unique-character-in-a-string
    return 0;
}