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
    int sumOfLeftLeaves(TreeNode* root) {
        int result=0;
        if(!root)
            return result;
        if(root->left && !root->left->left && !root->left->right)
            result+=root->left->val;
        return result+sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
    }
};
int main()
{
    // https://leetcode.com/problems/sum-of-left-leaves/
    return 0;
}