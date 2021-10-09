#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int pos=0;
        int ret=0;
        for(int i=1;i<=chars.size();i++) 
        {
            if(i==chars.size()||chars[i]!=chars[pos])
            {
                chars[ret++]=chars[pos];
                if(i-pos>1)
                    for(char ch:to_string(i-pos))
                        chars[ret++]=ch;
                pos=i;
            }
        }
        return ret;
    }
};
int main()
{
    // https://leetcode.com/problems/string-compression
    return 0;
}