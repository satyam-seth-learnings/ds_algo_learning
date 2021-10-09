#include <stdio.h>
#include<limits.h>

struct node { 
    int data; 
    struct node* left;
    struct node* right; 
}; 

int max(int a, int b)
{
	return a>b?a: b;
}
  
/* Function to find height of a tree */
int height(struct node* root, int *ans) 
{ 
    if (!root) 
        return 0; 
    int left_height = height(root->left, ans); 
    int right_height = height(root->right, ans); 
    *ans = max(*ans, 1 + left_height + right_height); 
    return 1 + max(left_height, right_height); 
} 
  
/* Computes the diameter of binary tree with given root. */
int diameter(struct node* root) 
{ 
    if (root == NULL) 
        return 0; 
    int ans = INT_MIN; // This will store the final answer 
    int height_of_tree = height(root, &ans); 
    return ans; 
} 
  
struct node* newNode(int data) 
{ 
    struct node* temp = (struct node*)malloc(sizeof(struct node)); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
  
    return (temp); 
} 
  
// Driver code 
int main() 
{ 
    struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    printf("Diameter is %d\n", diameter(root)); 
  
    return 0; 
} 

