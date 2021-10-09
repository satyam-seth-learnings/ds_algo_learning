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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *prev=dummy;
        while(head!=NULL)
        {
            if(head->next!=NULL && head->val==head->next->val)
            {
                while(head->next!=NULL && head->val==head->next->val)
                    head=head->next;
                prev->next=head->next;
            }
            else
                prev=prev->next;
            head=head->next;
        }
        return dummy->next;
    }
};
int main()
{
    // https://www.youtube.com/watch?v=R6-PnHODewY
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return 0;
}