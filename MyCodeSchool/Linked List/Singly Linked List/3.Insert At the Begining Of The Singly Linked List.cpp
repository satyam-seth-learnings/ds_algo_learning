#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
};

Node* InsertBegning(Node* head,int newdata)
{
	Node* temp=new Node();
	temp->data=newdata;
	temp->next=head;
	head=temp;
	return head;
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
	cout<<"Enter how many numbers:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the number:";
		cin>>x;
		head=InsertBegning(head,x);
		Print(head);
	}
}
