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
    vector<int> inorder(TreeNode* root) 
    {
        vector<int> r;
        if(!root) 
            return r;
        vector<int> x;
        if(root->left!=NULL) 
        {
            x=inorder(root->left);
            r.insert(r.end(),x.begin(),x.end());
        }
        r.push_back(root->val);
        if(root->right!=NULL) 
        {
            x=inorder(root->right);
            r.insert(r.end(),x.begin(),x.end());
        }
        return r;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1=inorder(root1);
        vector<int> tree2=inorder(root2);
        vector<int> result;
        int i=0,j=0;
        while(i<tree1.size() && j<tree2.size())
        {
            if(tree1[i]<tree2[j])
            {
                result.push_back(tree1[i]);
                i++;
            }
            else
            {
                result.push_back(tree2[j]);
                j++;
            }
        }
        if(i<tree1.size())
            result.insert(result.end(),tree1.begin()+i,tree1.end());
        if(j<tree2.size())
            result.insert(result.end(),tree2.begin()+j,tree2.end());
        return result;
    }
};
// Logic-2
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stack1,stack2;
        vector<int> result;
        while(root1 || root2 || !stack1.empty() || !stack2.empty())
        {
            while(root1)
            {
                stack1.push(root1);
                root1=root1->left;
            }
            while(root2)
            {
                stack2.push(root2);
                root2=root2->left;
            }
            if(stack2.empty() || !stack1.empty() && stack1.top()->val<=stack2.top()->val)
            {
                root1=stack1.top();
                stack1.pop();
                result.push_back(root1->val);
                root1=root1->right;
            }
            else
            {
                root2=stack2.top();
                stack2.pop();
                result.push_back(root2->val);
                root2=root2->right;
            }
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/all-elements-in-two-binary-search-trees
    return 0;
}