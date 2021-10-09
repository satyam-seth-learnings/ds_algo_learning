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
    bool isValidBSTHelper(TreeNode* root, long min, long max)
    {
        if(!root)
            return true;
        if(root->val>min && root->val<max)
        {
            bool temp1=isValidBSTHelper(root->left,min,root->val);
            bool temp2=isValidBSTHelper(root->right,root->val,max);
            return temp1 && temp2;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root,LONG_MIN,LONG_MAX);
    }
};
int main()
{
    // https://leetcode.com/problems/validate-binary-search-tree/
    return 0;
}