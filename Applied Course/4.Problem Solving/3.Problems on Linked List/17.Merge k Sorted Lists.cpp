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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> min_heap;
        for(auto head:lists)
        {
            while(head!=NULL)
            {
                min_heap.push(head->val);
                head=head->next;
            }
        }
        ListNode *dummy=new ListNode(-1);
        ListNode *head=dummy;
        while(!min_heap.empty())
        {
            head->next=new ListNode(min_heap.top());
            min_heap.pop();
            head=head->next;
        }
        return dummy->next;
    }
};
int main()
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}