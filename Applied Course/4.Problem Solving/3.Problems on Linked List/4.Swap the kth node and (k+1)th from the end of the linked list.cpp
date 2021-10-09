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
    ListNode* swapNode(ListNode* head,int k, int kp) {
        struct ListNode *dummy;
        dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
        dummy->next=head;
        struct ListNode *first=dummy,*second=dummy;
        for(int i=0;i<=kp;i++)
            first=first->next;
        while(first)
        {
            first=first->next;
            second=second->next;
        }
        swap(second->val,second->next->val);
        return dummy->next;
    }
};