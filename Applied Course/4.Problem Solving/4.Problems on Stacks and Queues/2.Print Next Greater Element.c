#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
 
struct stack
{
    int top;
    int items[STACKSIZE];
};

void push(struct stack *ps, int x)
{
    if (ps->top == STACKSIZE-1)
    {
        printf("Error: stack overflown");
        exit(0);
    }
    else
    {
        ps->top += 1;
        int top = ps->top;
        ps->items [top] = x;
    }
}
 
int isEmpty(struct stack *ps)
{
    return (ps->top == -1)? 1 : 0;
}
 
int pop(struct stack *ps)
{
    int temp;
    if (ps->top == -1)
    {
        printf("Error: stack underflow n");
        exit(0);
    }
    else
    {
        int top = ps->top;
        temp = ps->items [top];
        ps->top -= 1;
        return temp;
    }
}
 

void nextGreaterElement(int *arr, int n)
{
    int i = 0;
    struct stack s;
    s.top = -1;  // initialize top with -1
    int element, next;
 
    /* push the first element to stack */
    push(&s, arr[0]);

    for (i=1; i<n; i++)
    {
        next = arr[i];
        if(!isEmpty(&s))
        {
            element = pop(&s); // pop the stack element, if it is not empty
 
            while(element < next)
            {
                printf("\n%d --> %d", element, next);   
                if(isEmpty(&s)) // if stack is empty break
                   break;
                element = pop(&s);
            }
            if (element > next)
                push(&s, element);
        }

        push(&s, next);
    }
 
    while(!isEmpty(&s))
    {
        element = pop(&s);
        next = -1;
        printf("\n%d --> %d", element, next);
    }
}
 

int main()
{
    int arr[]= {4, 5, 2, 25};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextGreaterElement(arr, n);
    return 0;
}