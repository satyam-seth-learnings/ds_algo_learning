//Binary Search Tree Using Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct BstNode
{
	int data;
	struct BstNode *left;
	struct BstNode *right;
};
struct BstNode* CreateNode(int);
void Insert(struct BstNode*,int);
void Search(struct BstNode*,int);
int main()
{
	struct BstNode *root;
	root=Insert(root,15);
	root=Insert(root,19);
	Search(20);
}
struct BstNode* CreateNode(int data)
{
	struct BstNode *newnode;
	newnode=(struct BstNode*)malloc(sizeof(struct BstNode));
	return newnode;
}
void Insert(struct BstNode* root,int data)
{
	if(root==NULL)
		root=CreateNode(data);
	else if(data<=root->data)
		root->left=Insert(root->left);
	else
		root->right=Insert(root->right);
}
void Search(struct BstNode* root,int data)
{
	if(root==NULL)
		printf("Tree Is Empty.\n\n");
	else if(root->data==data)
		printf("Found");
	else if(data<=root->data)
		return Search(root->left,data);
	else if(data<=root->data)
		return Search(root->right,data);
}
