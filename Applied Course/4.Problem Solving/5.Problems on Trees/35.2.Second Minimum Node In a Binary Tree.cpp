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
    set<int> s;
    set<int> inorder(TreeNode* root)
    {
        if(!root)
            return s;
        inorder(root->left);
        s.insert(root->val);
        inorder(root->right);
        return s;
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s=inorder(root);
        if(s.size()>=2)
            return *(++s.begin());
        return -1;
    }
};
int main()
{
    // https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
    return 0;
}