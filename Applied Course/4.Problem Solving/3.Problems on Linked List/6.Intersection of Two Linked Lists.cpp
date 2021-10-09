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
// Logic-1 Nested Loop
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA,*temp2=headB;
        while(temp1)
        {
            temp2=headB;
            while(temp2)
            {
                if(temp1==temp2)
                    return temp1;
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        return NULL;
    }
};
// Logic-2 Counting
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA,*temp2=headB;
        int count1=0,count2=0;
        while(temp1)
        {
            count1++;
            temp1=temp1->next;
        }
        while(temp2)
        {
            count2++;
            temp2=temp2->next;
        }
        int n;
        if(count1<count2)
        {
            n=count2-count1;
            temp1=headB;
            temp2=headA;
        }
        else
        {
            n=count1-count2;
            temp1=headA;
            temp2=headB; 
        }
        while(n--)
            temp1=temp1->next;
        while(temp1 && temp2)
        {
            if(temp1==temp2)
                return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
    }
};
// Logic-3 Using Map
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1=headA,*temp2=headB;
        unordered_map<ListNode*,int> mp;
        while(temp1)
        {
            mp[temp1]++;
            temp1=temp1->next;
        }
        while(temp2)
        {
            if(mp[temp2])
                return temp2;
            temp2=temp2->next;
        }
        return NULL;
    }
};
int main()
{
    // https://leetcode.com/problems/intersection-of-two-linked-lists/
    return 0;
}