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
// Logic-1
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        int count=0;
        ListNode *temp=head;
        while(temp)
        {
            count++;
            temp=temp->next;
        }
        int n=count/2;
        temp=head;
        while(n--)
            temp=temp->next;
        return temp;
    }
};
// Logic-2
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *fast=head,*slow=head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
int main()
{
    // https://leetcode.com/problems/middle-of-the-linked-list/
    return 0;
}