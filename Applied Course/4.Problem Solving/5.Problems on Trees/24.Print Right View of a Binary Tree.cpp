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
    vector<int> rightSideView(TreeNode* root) {
        levelOrder(root,0);
        return v;
    }
    void levelOrder(TreeNode* root,int level)
    {
        if(root==NULL)
            return;
        if(v.size()==level)
            v.push_back(root->val);
        levelOrder(root->right,level+1);
        levelOrder(root->left,level+1);
    }
};
// Logic-2
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            while(count-->0)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(count==0)
                    v.push_back(temp->val);
                if(temp->left!=NULL)
                    q.push(temp->left);
                if(temp->right!=NULL)
                    q.push(temp->right);
            }
        }
        return v;
    }
};
int main()
{
    // https://leetcode.com/problems/binary-tree-right-side-view
    return 0;
}