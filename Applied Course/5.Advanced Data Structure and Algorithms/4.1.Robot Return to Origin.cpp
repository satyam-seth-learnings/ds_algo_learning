#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool judgeCircle(string moves) {
        unordered_map<char,int> x_dir={{'L',1},{'R',-1}};
        unordered_map<char,int> y_dir={{'U',1},{'D',-1}};
        int x=0,y=0;
        for(auto &move:moves)
        {
            x+=x_dir[move];
            y+=y_dir[move];
        }
        return x==0 && y==0;
    }
};
int main()
{
    // https://leetcode.com/problems/robot-return-to-origin/
    return 0;
}