#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    void DFS(vector<vector<int>>& M,int i,int n,vector<bool>& visited)
    {
        visited[i]=true;
        for(int j=0;j<n;j++)
            if(M[i][j]==1 && visited[j]==false)
                DFS(M,j,n,visited);
    }                
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int result=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                DFS(isConnected,i,n,visited);
                result++;
            }
        }
        return result;
    }
};
// Logic-2
class Solution {
public:
    int find(vector<int>& parent,int i)
    {
        if(parent[i]==-1)
            return i;
        return find(parent,parent[i]);
    }
    
    void Union(vector<int>& parent,int x,int y)
    {
        int xset=find(parent,x);
        int yset=find(parent,y);
        if(xset!=yset)
            parent[yset]=xset;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(isConnected[i][j]==1 && i!=j)
                    Union(parent,i,j);
        int result=0;
        for(int i=0;i<n;i++)
            if(parent[i]==-1)
                result++;
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/number-of-provinces
    return 0;
}