#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void check(vector<int> v,int &p,int k)
    {
        for(int i=0;i<v.size();i++)
        {
            int s=v[i];
           for(int j=i+1;j<v.size();j++)
           {
               if(s<=k)
                   p=max(p,s);
               s=s+v[j];
           }
            if(s<=k)
                p=max(p,s);
        }
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),res=INT_MIN;
        if(n==0)
            return 0;
        int m=matrix[0].size();
        if(m==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            vector<int> v(m,0);
            for(int j=i;j<n;j++)
            {
                for(int k=0;k<m;k++)
                    v[k]=v[k]+matrix[j][k];
                check(v,res,k);
            }
        }
        return(res);
    }
};
int main()
{
    // https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
    return 0;
}