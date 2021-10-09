#include <stdio.h>
#include<stdlib.h>



struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  

void findMinMax(struct Node *node, int *min, int *max, int hd)
{
     if (node == NULL) return;
  
 
    if (hd < *min)  *min = hd;
    else if (hd > *max) *max = hd;
 
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}
  
void printVerticalLine(struct Node *node, int line_no, int hd)
{
    if (node == NULL) return;
    if (hd == line_no)
        printf("%d",node->data);
    printVerticalLine(node->left, line_no, hd-1);
    printVerticalLine(node->right, line_no, hd+1);
}
  
void verticalOrder(struct Node *root)
{
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
  
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        printf("\n");
    }
}
 
 int main()
{
    // Create binary tree shown in above figure
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
  
    
    verticalOrder(root);
  
    return 0;
}
