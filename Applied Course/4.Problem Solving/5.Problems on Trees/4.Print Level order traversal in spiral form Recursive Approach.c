#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
  

struct node { 
    int data; 
    struct node* left; 
    struct node* right; 
}; 

/* Compute the "height" of a tree -- */
int height(struct node *root) 
{ 
    if(!root) 
        return 0; 
    else { 
        /* compute the height of each subtree */
        int lheight = height(root->left); 
        int rheight = height(root->right); 
        return (lheight >rheight)?(lheight+1): (rheight+1);
    } 
} 
  
//Create a new node
struct node* newNode(int data) 
{ 
    struct node *temp = (struct node*) 
        malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level, int flag) 
{ 
    if(!root) 
        return; 
    if(level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) { 
        if (flag) { 
            printGivenLevel(root->left, level - 1, flag); 
            printGivenLevel(root->right, level - 1, flag); 
        } 
        else { 
            printGivenLevel(root->right, level - 1, flag); 
            printGivenLevel(root->left, level - 1, flag); 
        } 
    } 
} 
    
/* Function to print spiral traversal of a tree*/
void printSpiral(struct node* root) 
{ 
    // get height of the tree
    int h = height(root); 
    int i; 
  
    /*flag -> Left to Right. If this variable is set, 
      then the given level is traversed from left to right. */
    int flag = 0; 
    for (i = 1; i <= h; i++) { 
        printGivenLevel(root, i, flag); 
  
        /*change flag value to traverse next level in opposite order*/
        flag = !flag; 
    } 
} 
  
int main() 
{ 
    struct node* root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->left = newNode(70); 
    root->left->right = newNode(60); 
    root->right->left = newNode(50); 
    root->right->right = newNode(40); 
    printf("Spiral Order traversal of binary tree is \n"); 
    printSpiral(root); 
  
    return 0; 
} 
