#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Node 
{ 
    struct Node *left, *right, *rthread; 
    int key; 
}; 
  
// A utility function to create a new BST node 
struct Node *newNode(int item) 
{ 
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->key = item; 
    temp->rthread = temp->left = temp->right = NULL; 
    return temp; 
} 
  
/* A utility function to insert a new node with 
   given key in BST */
struct Node *insert(struct Node *node, int key) 
{ 
    if (node == NULL) return 
        newNode(key); 
  
    if (key < node->key) 
    { 
        node->left  = insert(node->left, key); 
        node->left->rthread = node; 
    } 
    else if (key > node->key) 
    { 
        node->right = insert(node->right, key); 
        node->right->rthread = node; 
    } 
  
    return node; 
} 

void inorder(struct Node *root) 
{ 
    bool leftdone = false; 
  
    while (root) 
    { 

        if (!leftdone) 
        { 
            while (root->left) 
                root = root->left; 
        } 
  
        printf("%d ", root->key); 
  
        leftdone = true; 
  
        if (root->right) 
        { 
            leftdone = false; 
            root = root->right; 
        } 
  
        else if (root->rthread) 
        { 

            while (root->rthread && 
                   root == root->rthread->right) 
                root = root->rthread; 
            if (!root->rthread) 
                break; 
            root = root->rthread; 
        } 
        else break; 
    } 
} 

int main(void) 
{ 
    struct Node * root = NULL; 
  
    root = insert(root, 24); 
    root = insert(root, 27); 
    root = insert(root, 29); 
    root = insert(root, 34); 
    root = insert(root, 14); 
    root = insert(root, 4); 
    root = insert(root, 10); 
    root = insert(root, 22); 
    root = insert(root, 13); 
    root = insert(root, 3); 
    root = insert(root, 2); 
    root = insert(root, 6); 
  
    printf("Inorder traversal is \n"); 
    inorder(root); 
  
    return 0; 
}

