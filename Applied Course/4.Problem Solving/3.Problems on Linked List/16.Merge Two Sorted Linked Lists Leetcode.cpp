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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *mergeList, *temp;
        if(l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if(l1->val <= l2->val) {
            mergeList = l1;
            l1 = l1->next;
        }
        else {
            mergeList = l2;
            l2 = l2->next;
        }
        temp = mergeList;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }       
        }
        temp->next = (!l1)? l2: l1;
        return mergeList;
    }
};
// Logic-2
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if(l1->val <= l2->val)
        {
            l1->next=mergeTwoLists(l1->next,l2);
            return l1;
        }
        else 
        {
            l2->next=mergeTwoLists(l2->next,l1);
            return l2;
        }
    }
};
int main()
{
    // https://leetcode.com/problems/merge-two-sorted-lists/submissions/
    return 0;
}