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
    int prev=INT_MIN,count=1,max=0;
    void traverse(TreeNode* root,vector<int> &modes)
    {
        if(!root)
            return;
        traverse(root->left,modes);
        if(prev!=INT_MIN)
            if(prev==root->val)
                count++;
            else
                count=1;
        if(count>max)
        {
            max=count;
            modes.clear();
            modes.push_back(root->val);
        }
        else if(count==max)
            modes.push_back(root->val);
        prev=root->val;
        traverse(root->right,modes);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        traverse(root,modes);
        return modes;
    }
};
int main()
{
    // https://leetcode.com/problems/find-mode-in-binary-search-tree/
    return 0;
}