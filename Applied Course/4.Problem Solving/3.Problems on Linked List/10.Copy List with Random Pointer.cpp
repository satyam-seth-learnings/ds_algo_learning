#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Logic-1
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> nodeMap;
        if(!head)
            return NULL;
        Node* dummy=new Node(0);
        Node* curnew=dummy;
        Node* cur=head;
        while(cur)
        {
            curnew->next=new Node(cur->val);
            nodeMap[cur]=curnew->next;
            curnew=curnew->next;
            cur=cur->next;
        }
        curnew=dummy->next;
        cur=head;
        while(cur)
        {
            curnew->random=nodeMap[cur->random];
            curnew=curnew->next;
            cur=cur->next;
        }
        return dummy->next;
    }
};
// Logic-2
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        Node* curr=head,*temp;
        while(curr)
        {
            temp=curr->next;
            Node* temp1=new Node(0);
            temp1->val=curr->val;
            temp1->next=NULL;
            temp1->random=NULL;
            curr->next=temp1;
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr)
        {
            if(curr->next)
                curr->next->random=curr->random?curr->random->next:curr->random;
            curr=curr->next?curr->next->next:curr->next;
        }
        Node *original=head,*copy=head->next;
        temp=copy;
        while(original && copy)
        {
            original->next=original->next?original->next->next:original->next;
            copy->next=copy->next?copy->next->next:copy->next;            
            original=original->next;
            copy=copy->next;
        }
        return temp;
    }
};
int main()
{
    // https://leetcode.com/problems/copy-list-with-random-pointer/
    return 0;
}