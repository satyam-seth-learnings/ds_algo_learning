#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
};

void InsertPos(int newdata,int n)
{
	Node* temp=new Node();
	temp1->data=newdata;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;	
		return;
	}
	Node* temp2=head;
	for(int i=0,i<n-2;i++)
		temp2=temp2-next;
	temp1->next=temp2->next;
	temp2->next=temp1;
}

void Print(Node* head)
{
	cout<<"List: ";
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

int main()
{
	int n,x;
	Node* head=NULL;
	InsertPos(2,1);
	InsertPos(3,2);
	InsertPos(4,1);
	InsertPos(5,2);
	Print(head);
}
