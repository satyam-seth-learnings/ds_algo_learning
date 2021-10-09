#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *preSlow=head;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            preSlow=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        preSlow->next=NULL;
        ListNode *leftSide=sortList(head);
        ListNode *rightSide=sortList(slow);
        return merge(leftSide,rightSide);
    }
    ListNode* merge(ListNode *head1,ListNode *head2)
    {
        ListNode *sortedTemp=(struct ListNode*)malloc(sizeof(struct ListNode));
        sortedTemp->val=0;
        ListNode *currentNode=sortedTemp;
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                currentNode->next=head1;
                head1=head1->next;
            }
            else
            {
                currentNode->next=head2;
                head2=head2->next;
            }
            currentNode=currentNode->next;
        }
        if(head1!=NULL)
        {
            currentNode->next=head1;
            head1=head1->next;
        }
        if(head2!=NULL)
        {
            currentNode->next=head2;
            head2=head2->next;
        }
        return sortedTemp->next;
    }
};
int main()
{
    // https://leetcode.com/problems/sort-list/
    return 0;
}