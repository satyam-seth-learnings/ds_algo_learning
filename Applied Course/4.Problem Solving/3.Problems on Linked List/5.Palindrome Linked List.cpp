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
    bool isPalindrome(ListNode* head) {
        int count=0;
        stack<int> s;
        struct ListNode *temp=head;
        while(temp)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(temp)
        {
            if(temp->val!=s.top())
                return false;
            temp=temp->next;
            s.pop();
        }
        return true;
    }
};
// Logic-2
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
    void reverse(struct ListNode** head) 
    { 
        struct ListNode* prev   = NULL; 
        struct ListNode* current = *head; 
        struct ListNode* next; 
        while (current != NULL) 
        { 
            next  = current->next; 
            current->next = prev; 
            prev = current; 
            current = next; 
        } 
        *head = prev; 
    }
    bool compare(struct ListNode* temp1,struct ListNode* temp2)
    {
        while(temp1 && temp2)
        {
            if(temp1->val==temp2->val)
            {
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else
                return false;
        }
        if (temp1 == NULL && temp2 == NULL) 
            return true; 
        return false;
    }
    bool isPalindrome(ListNode* head) {
        struct ListNode *slow_ptr = head, *fast_ptr = head; 
        struct ListNode *second_half, *prev_of_slow_ptr = head; 
        struct ListNode *midnode = NULL;
        bool res = true; 
        if (head!=NULL && head->next!=NULL) 
        { 
            while (fast_ptr != NULL && fast_ptr->next != NULL) 
            { 
                fast_ptr = fast_ptr->next->next;
                prev_of_slow_ptr = slow_ptr; 
                slow_ptr = slow_ptr->next; 
            } 
            if (fast_ptr != NULL) 
            { 
                midnode = slow_ptr; 
                slow_ptr = slow_ptr->next; 
            } 

            second_half = slow_ptr; 
            prev_of_slow_ptr->next = NULL;  
            reverse(&second_half);  
            res = compare(head, second_half);
            reverse(&second_half);

             if (midnode != NULL)  
             { 
                prev_of_slow_ptr->next = midnode; 
                midnode->next = second_half; 
             } 
             else  prev_of_slow_ptr->next = second_half; 
        } 
        return res;
    }
};
int main()
{
    // https://leetcode.com/problems/palindrome-linked-list/
    return 0;
}