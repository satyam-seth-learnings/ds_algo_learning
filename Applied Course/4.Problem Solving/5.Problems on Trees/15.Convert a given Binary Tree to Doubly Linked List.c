#include <stdio.h> 
#include <stdlib.h> 
  
// Structure for tree and linked list 
struct node
{ 
    int data; 
    struct node *left, *right; 
}; 
  

void BinaryToDLL(struct node* root, struct node** head) 
{ 
    // Base cases 
    if (!root) 
        return; 
  
    // Recursively convert right subtree 
    BinaryToDLL(root->right, head); 
  
    // insert root into DLL 
    root->right = *head; 
  
    // Change left pointer of previous head 
    if (*head) 
        (*head)->left = root; 
  
    // Change head of Doubly linked list 
    *head = root; 
  
    // Recursively convert left subtree 
    BinaryToDLL(root->left, head); 
} 
  
// create a new node 
struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
void printList(struct node* head) 
{ 
     
    while (head) 
    { 
        printf("%d ", head->data); 
        head = head->right; 
    } 
} 
  
// Driver program to test above function 
int main() 
{ 
    struct node* root = newNode(5); 
    root->left = newNode(3); 
    root->right = newNode(6); 
    root->left->left = newNode(1); 
    root->left->right = newNode(4); 
    root->right->right = newNode(8); 
    root->left->left->left = newNode(0); 
    root->left->left->right = newNode(2); 
    root->right->right->left = newNode(7); 
    root->right->right->right = newNode(9); 
  
    struct node* head = NULL; 
    BinaryToDLL(root, &head); 
  
    printList(head); 
  
    return 0; 
} 