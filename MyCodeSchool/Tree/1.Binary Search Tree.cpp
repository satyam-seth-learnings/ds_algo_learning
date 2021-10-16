#include<iostream>
using namespace std;
struct BstNode{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetNewNode(int data)
{
	BstNode* newNode=new BstNode();
	newNode->data=data;
	newNode->left=newNode->right=NULL;
	return newNode;
}
BstNode* Insert(BstNode* root, int data)
{
	if(root==NULL)	// empty tree
		root=GetNewNode(data);
	
	else if(data <= root->data)
		root->left=Insert(root->left,data);
	
	else
		root->right=Insert(root->right,data);
	
	return root;
}
bool Search(BstNode* root,int data)
{
	if(root==NULL)
		return false;
	else if(root->data==data)
		return true;
	else if(data<=root->data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}
int FindMin(BstNode* root)
{
	if(root==NULL)
	{
		cout<<"Error: Tree is empty"<<endl;
		return -1;
	}

// Using loop
/*	while(root->left!=NULL)
		root=root->left;
	return root->data;	*/
	
// Using recursion
	else if(root->left==NULL)
		return root->data;
	// Search in left subtree
	return FindMin(root->left);
}
int FindMax(BstNode* root)
{
	if(root==NULL)
	{
		cout<<"Error: Tree is empty"<<endl;
		return -1;
	}

// Using loop
/*	while(root->right!=NULL)
		root=root->right;
	return root->data;	*/
	
// Using recursion
	else if(root->right==NULL)
		return root->data;
	// Search in left subtree
	return FindMin(root->right);
}
int main()
{
	BstNode* root=NULL;	// Creating an empty tree
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,25);
	root=Insert(root,2);
	root=Insert(root,8);
	root=Insert(root,12);
	cout<<"Minimum Element: "<<FindMin(root)<<endl;
	cout<<"Maximum Element: "<<FindMax(root)<<endl;
	int number;
	cout<<"Enter number be searched: ";
	cin>>number;
	if(Search(root,number)==true)
		cout<<"Found";
	else
		cout<<"Not Found";
}
