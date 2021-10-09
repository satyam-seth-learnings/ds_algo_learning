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
    int find(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 1;
        int l=find(root->left,ans);
        int r=find(root->right,ans);
        if(l==1 || r==1)
        {
            ans++;
            return 2;
        }
        else if(l==0 && r==0)
            return 1;
        else
            return 0;
    }
    int minCameraCover(TreeNode* root) {
        int ans=0;
        if(find(root,ans)==1)
            ans++;
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/binary-tree-cameras
    return 0;
}