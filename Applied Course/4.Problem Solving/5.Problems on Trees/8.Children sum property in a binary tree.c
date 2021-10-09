#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
// creation of node.
struct node* newNode(int data) 
{ 
  struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  temp->data = data; 
  temp->left = NULL; 
  temp->right = NULL; 
  return temp; 
} 
//Function to check sum property.
int checkSumProperty(struct node* root) 
{ 
  
  int ldata = 0,  rdata = 0; 
  //If no node or single node.
  if(root == NULL || (root->left == NULL && root->right == NULL)) 
    return 1; 
  else
  { 

    if(root->left != NULL) 
      ldata = root->left->data; 
  
    if(root->right != NULL) 
      rdata = root->right->data; 
  
    if((root->data == ldata + rdata)&& checkSumProperty(root->left) && checkSumProperty(root->right)) 
      return 1; 
    else
      return 0; 
  } 
} 
  

  
int main() 
{ 
  struct node *root  = newNode(15); 
  root->left         = newNode(10); 
  root->right        = newNode(5); 
  root->left->left   = newNode(6); 
  root->left->right  = newNode(4); 
  root->right->left = newNode(3); 
  root->right->right = newNode(2); 
  if(checkSumProperty(root)) 
    printf("children sum property "); 
  else
    printf("not satisfy the children sum property "); 
  
  return 0; 
}