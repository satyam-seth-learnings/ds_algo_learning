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
    vector<int> v;
    vector<int> inorder(TreeNode* root)
    {
        if(!root)
            return v;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
        return v;
    }
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root)[k-1];
    }
};
// Logic-2
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        while(true)
        {
            while(root)
            {
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            k-=1;
            if(k==0)
                return root->val;
            root=root->right;
        }
    }
};
int main()
{
    // https://leetcode.com/problems/kth-smallest-element-in-a-bst/
    return 0;
}