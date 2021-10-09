#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
   int data; 
   struct node* left; 
   struct node* right; 
}; 
  
/* If target element is present in tree, then prints the ancestors 
   and returns 1, otherwise returns 0. */
int printAncestors(struct node *root, int target) 
{ 
  if(!root) 
     return 0; 
  if(root->data == target) 
     return 1; 
  
  /* If target is present in either left or right subtree of this node, 
     then print this node */
  if(printAncestors(root->left, target) || printAncestors(root->right, target) ) 
  { 
    printf("%d ", root->data);
    return 1; 
  } 
  return 0; 
} 
  
/* create a new node*/
struct node* newNode(int data) 
{ 
  struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  temp->data = data; 
  temp->left = NULL; 
  temp->right = NULL; 
  
  return temp; 
} 
  

int main() 
{ 
  struct node *root = newNode(10); 
  root->left        = newNode(20); 
  root->right       = newNode(30); 
  root->left->left  = newNode(40); 
  root->left->right = newNode(50); 
  root->left->left->left  = newNode(70); 
  
  printAncestors(root, 70); 
  
  getchar(); 
  return 0; 
} 