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
// Logic-1 Counting
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=0;
        struct ListNode *dummy,*temp=head;
        dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->val=0;
        dummy->next=head;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        length-=n;
        temp=dummy;
        while(length--)
            temp=temp->next;
        temp->next=temp->next->next;
        return dummy->next;
    }
};
// Logic-2 Two Pointer Approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *dummy;
        dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->next=head;
        struct ListNode *first=dummy,*second=dummy;
        for(int i=0;i<=n;i++)
            first=first->next;
        while(first)
        {
            first=first->next;
            second=second->next;
        }
        second->next=second->next->next;
        return dummy->next;
    }
};
int main()
{
    // https://leetcode.com/problems/remove-nth-node-from-end-of-list/
    return 0;
}