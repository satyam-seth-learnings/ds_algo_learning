#include <stdio.h>
#define MAX 20
#define N 10

int stack[20];
int top=-1;
int mat[N][N]={{0,0,0,0,1},
			   {0,0,0,0,1},
			   {0,0,0,0,1},
		       {0,0,0,0,1},
		       {0,0,0,0,0}};

// Function to check both persons knows each other or not
int HaveAcquaintance(int a, int b)
{
	return mat[a][b];
}


//Function to check the stack is empty or not
int isEmpty()
{
	return ((top) == -1);
}

// Function for push the element into stack
void push(int data)
{
	if(top==MAX){
		printf("Stack overflow");
		return;
	}
	stack[++top] = data;
}

// Function to pop an element from the stack
int pop()
{
	if(isEmpty()){
		printf("Stack Empty");
		return -1;
	}
	else{
		int value = stack[top--];
		return value;
	}
}

// Function to check size of the stack
int size()
{
	return top+1;
}

// Returns -1 if celebrity is not present. If present, returns index(id)
//(value from 0 to n-1). 

int findCeleb(int n)
{
	int celeb;
	// push everybody to stack
	for(int i; i<n; i++)
		push(i);
	
	// get top2 elements
	int temp1 = pop();
	int temp2 = pop();

	//Find potential celebrity
	while(size()>1)
	{
		if(HaveAcquaintance(temp1,temp2))
			temp1 = pop();
		else
			temp2 = pop();
	}
	
	celeb = pop();

	if(HaveAcquaintance(celeb,temp2))
		celeb=temp2;
	if(HaveAcquaintance(celeb,temp1))
		celeb=temp1;

	// Check if Celeb is actually a celebrity or not
	for (int i = 0; i < n; i++) 
    {  
    	// If any person doesn't know 'p' or 'p' doesn't know any person, return -1
        if ( (i != celeb) && (HaveAcquaintance(celeb, i) || !HaveAcquaintance(i, celeb)) ) 
            return -1; 
    } 
    return celeb;
}

int main()
{
	int n = 5;
	int value = findCeleb(n);
	if(value>0)
		printf("the celebrity is %d\n",value);
	else{
		printf("celebrity not found\n");
	}
	return 0;
}