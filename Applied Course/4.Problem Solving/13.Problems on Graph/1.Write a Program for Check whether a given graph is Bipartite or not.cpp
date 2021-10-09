include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ans=true;
    void dfssol(int i,int parent,vector<int>& visited_1_2,vector<vector<int>>& adj,int color)
    {
        visited_1_2[i]=color;
        for(auto u:adj[i])
        {
            if(visited_1_2[u]==-1)
            {
                dfssol(u,i,visited_1_2,adj,3-color);
            }
            else if(visited_1_2[u]==color)
            {
                ans=false;
                break;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> visited_1_2(n,-1);
           for(int i=0;i<n;++i)
           {
               if(visited_1_2[i]==-1)
               {
                    dfssol(i,-1,visited_1_2,adj,2);
               }
                if(ans==false) break;
           }
           return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/is-graph-bipartite
    return 0;
}