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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        if(low<=root->val && root->val<=high)
            return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
        else
            return rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};
int main()
{
    // https://leetcode.com/problems/range-sum-of-bst
    return 0;
}