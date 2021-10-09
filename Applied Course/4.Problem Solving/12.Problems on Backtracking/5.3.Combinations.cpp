#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef vector<vector<int> > vvi; 
    void backtrack(int n,int k,vvi &res,vector<int> &op,int start=0)
    {
        if(op.size()==k)
        {
            res.emplace_back(op);
            return ;
        }
        for(int i=start+1;i<=n;i++)
        {
            op.emplace_back(i);   //do
            backtrack(n,k,res,op,i); //explore
            op.pop_back(); //undo
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> op;
        backtrack(n,k,res,op);
        return res;
    }
};
int main()
{
    // https://leetcode.com/problems/combinations/
    return 0;
}