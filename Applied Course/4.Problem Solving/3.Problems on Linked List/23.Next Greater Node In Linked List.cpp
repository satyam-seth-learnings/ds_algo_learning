#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> node_vals;
        stack<int> s;
        ListNode *current_node=head;
        while(current_node!=NULL)
        {
            node_vals.push_back(current_node->val);
            current_node=current_node->next;
        }
        vector<int> ans(node_vals.size(),0);
        for(int i=0;i<node_vals.size();i++)
        {
            while(!s.empty() && node_vals[s.top()]<node_vals[i])
            {
                ans[s.top()]=node_vals[i];
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
int main()
{
    // https://www.youtube.com/watch?v=wVsGnpXoxPI
    // https://leetcode.com/problems/next-greater-node-in-linked-list/
    return 0;
}