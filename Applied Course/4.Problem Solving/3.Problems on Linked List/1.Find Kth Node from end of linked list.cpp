//https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/
// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/

//Logic-1
int getNthFromLast(Node *head, int n)
{
       // Your code here
    int len=0;
    struct Node *temp=head;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    if(len<n)
        return -1;
    temp=head;
    for(int i=0;i<len-n;i++)
        temp=temp->next;
    return temp->data;
}
//Logic-2
int getNthFromLast(Node *head, int n)
{
   // Your code here
    int count=0;
    struct Node *preptr=head;
    struct Node *ptr=head;
    if(head!=NULL)
    {
        while(count<n)
        {
            if(ptr==NULL)
                return -1;
            ptr=ptr->next;
            count++;
        }
    }
    if(ptr==NULL)
        return preptr->data;
    else
    {
        while(ptr!=NULL)
        {
            preptr=preptr->next;
            ptr=ptr->next;
        }
        return preptr->data;
    }
}