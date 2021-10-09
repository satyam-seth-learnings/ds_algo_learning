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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        ListNode *curr=head;
        while(curr!=NULL)
        {
            ListNode *temp=curr->next;
            ListNode *prev=dummy;
            ListNode *nxt=dummy->next;
            while(nxt!=NULL)
            {
                if(nxt->val>curr->val)
                    break;
                prev=nxt;
                nxt=nxt->next;
            }
            curr->next=nxt;
            prev->next=curr;
            curr=temp;
        }
        return dummy->next;
    }
};
int main()
{
    // https://leetcode.com/problems/insertion-sort-list/
    return 0;
}