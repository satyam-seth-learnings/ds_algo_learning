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
//Function to get leafcount.
int getLeafCount(struct node* root) 
{ 
  if(root == NULL)        
    return 0; 
  if(root->left == NULL && root->right==NULL)       
    return 1;             
  else 
    return getLeafCount(root->left)+ getLeafCount(root->right);       
} 
  
int main() 
{ 
  struct node *root = newNode(10); 
  root->left        = newNode(20); 
  root->right       = newNode(30); 
  root->left->left  = newNode(40); 
  root->left->right = newNode(50);     
    
  int val=getLeafCount(root); 

  printf("Number of leaf : %d",val);
  return 0; 
} 