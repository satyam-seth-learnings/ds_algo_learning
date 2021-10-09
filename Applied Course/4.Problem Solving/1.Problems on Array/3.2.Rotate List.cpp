#include<iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        auto tail=head;
        int n=1;
        while(tail->next)
        {
            n++;
            tail=tail->next;
        }
        k%=n;
        if(k==0)
            return head;
        tail->next=head;
        auto new_tail=tail;
        int steps=n-k;
        while(steps--)
            new_tail=new_tail->next;
        auto new_head=new_tail->next;
        new_tail->next=NULL;
        return new_head;
    }
};
int main()
{
//   https://leetcode.com/problems/rotate-list/  
    return 0;
}