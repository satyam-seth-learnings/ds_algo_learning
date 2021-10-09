#include<bits/stdc++.h>
using namespace std;
// Logic-1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Logic-1
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        unordered_map<struct ListNode*,bool> m;
        struct ListNode *ptr=head;
        while(ptr)
        {
            if(m[ptr]==false)
            {
                m[ptr]=true;
                ptr=ptr->next;
            }
            else
                return true;
        }
        return false;
    }
};
// Logic-2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode *fastPtr=head, *slowPtr=head;
        while(fastPtr&&fastPtr->next)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if (fastPtr == slowPtr) 
                return true;
        }
        return false;
    }
};
int main()
{
    // https://leetcode.com/problems/linked-list-cycle/
    return 0;
}