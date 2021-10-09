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
// Logic-1
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val==val)
            return root;
        if(root->val>val)
            return searchBST(root->left,val);
        return searchBST(root->right,val);
    }
};
// Logic-2
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val)
            if(root->val>val)
                root=root->left;
            else
                root=root->right;
        return root;
    }
};
int main()
{
    // https://leetcode.com/problems/search-in-a-binary-search-tree/
    return 0;
}