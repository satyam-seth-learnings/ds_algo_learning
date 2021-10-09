#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans; 
        queue<TreeNode*> q; 
        q.push(root); 
        while (!q.empty()) 
        {
            double sm=0,cnt=0; 
            for (int i=0,n=q.size();i<n;i++) 
            {
                TreeNode* node=q.front(); 
                q.pop(); 
                if(node) 
                {
                    sm+=node->val; 
                    cnt++; 
                    q.push(node->left);
                    q.push(node->right); 
                }
            }
            if(cnt)
                ans.push_back(sm/cnt); 
        }
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/average-of-levels-in-binary-tree/
    return 0;
}