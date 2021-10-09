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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(root==NULL)
            return v;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        s1.push(root);
        struct TreeNode *temp;
        while(s1.size()!=0 || s2.size()!=0)
        {
            vector<int>x;
            vector<int>y;
            while(s1.size()!=0)
            {
                temp=s1.top();
                s1.pop();
                x.push_back(temp->val);
                if(temp->left)
                   s2.push(temp->left);
                if(temp->right)
                    s2.push(temp->right);
            }
            if(x.size()!=0)
            {
                v.push_back(x);
                x.clear();
            }
            while(s2.size()!=0)
            {
                temp=s2.top();
                s2.pop();
                y.push_back(temp->val);
                if(temp->right)
                    s1.push(temp->right);
                if(temp->left)
                    s1.push(temp->left);
            }
            if(y.size()!=0)
            {
                v.push_back(y);
                y.clear();
            }
        }
        return v;
    }
};
int main()
{
    // https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
    return 0;
}