#include<bits/stdc++.h>
using namespace std;
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
    ListNode *detectCycle(ListNode *head) {
        struct ListNode *fastPtr=head, *slowPtr=head;
        while(fastPtr&&fastPtr->next)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if (fastPtr == slowPtr) 
            {
                slowPtr=head;
                while(slowPtr!=fastPtr)
                {
                    slowPtr=slowPtr->next;
                    fastPtr=fastPtr->next;
                }
                return slowPtr;
            }
        }
        return NULL;
    }
};
int main()
{
    // https://leetcode.com/problems/linked-list-cycle-ii/
    return 0;
}