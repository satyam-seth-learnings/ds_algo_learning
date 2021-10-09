#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
         vector<vector<int>> visited(heightMap.size(), vector<int>(heightMap[0].size(), 0));
        set<vector<int>> s;
        int sv = heightMap.size();
        int sh = heightMap[0].size();
        for(int i=0; i<heightMap.size(); i++){
            s.insert({heightMap[i][0], i, 0});
            s.insert({heightMap[i][sh-1], i, sh-1});
        }
        for(int i=0; i<heightMap[0].size(); i++){
            s.insert({heightMap[0][i], 0, i});
            s.insert({heightMap[sv-1][i], sv-1, i});
        }
        int maxi = (*s.begin())[0];
        int ret = 0;
        while(s.size()){
            int curh = (*s.begin())[0];
            vector<int> cur = {(*s.begin())[1], (*s.begin())[2]};
            s.erase(*s.begin());
            if(visited[cur[0]][cur[1]])continue;
            visited[cur[0]][cur[1]] = 1;
            if(curh < maxi){
                ret += maxi - curh;
            }
            else{
                maxi = curh;
            }
            if(cur[0]-1 >= 0){
                if(visited[cur[0]-1][cur[1]] == 0)
                    s.insert({heightMap[cur[0]-1][cur[1]], cur[0]-1, cur[1]});
            }
            if(cur[1]-1 >= 0){
                if(visited[cur[0]][cur[1]-1] == 0)
                    s.insert({heightMap[cur[0]][cur[1]-1], cur[0], cur[1]-1});
            }
            if(cur[0]+1 < sv){
                if(visited[cur[0]+1][cur[1]] == 0)
                    s.insert({heightMap[cur[0]+1][cur[1]], cur[0]+1, cur[1]});
            }
            if(cur[1]+1 < sh){
                if(visited[cur[0]][cur[1]+1] == 0)
                    s.insert({heightMap[cur[0]][cur[1]+1], cur[0], cur[1]+1});
            }
        }
        return ret; 
    }
};
int main()
{
    // https://leetcode.com/problems/trapping-rain-water-ii/
    return 0;
}