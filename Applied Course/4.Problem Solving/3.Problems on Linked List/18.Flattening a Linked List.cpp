
#include <stdio.h>
#include <stdlib.h>

// A Linked List Node
struct node
{
    int data;
    struct node *right;
    struct node *down;
};

void push (struct node **head_ref, int new_data)
{
    struct node* new_node = (struct node *) malloc(sizeof(struct node));
    new_node->right = NULL;
    new_node->data = new_data;
    new_node->down = (*head_ref);
    (*head_ref) = new_node;
}

/*  print nodes in the flattened linked list */
void printList(struct node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->down;
    }
}

// A utility function to merge two sorted linked lists
struct node* merge( struct node* head1, struct node* head2 )
{
   
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    // Compare the data members of head nodes of both lists
    // and put the smaller one in result
    struct node* result=NULL;
    struct node* temp=NULL;
    if(head1->data < head2->data){
        result=temp=head1;
        head1=head1->down;
    }
        else{
        result = temp = head2;
        head2 = head2->down;
    }
    while(head1 && head2){
        if(head1->data < head2->data){
           temp->down=head1;
           temp=head1;
           head1=head1->down;
        }
        else{
           temp->down=head2;
           temp=head2;
           head2=head2->down;
        }
    }
    temp->down = head1 ?head1: head2;
    return result;
}

// flattens a given linked list
struct node* flatten (struct node* head)
{
    // Base cases
    if (!head|| !head->right)
        return head;

    struct node *rem=head->right;
    struct node *newh=head;
    while(rem){
        struct node *l2=rem;
        rem=rem->right;
        newh=merge(newh,l2);
    }
    return newh;
}

// Driver program to test above functions
int main()
{
    struct node* head = NULL;

    
    push( &head, 30 );
    push( &head, 8 );
    push( &head, 7 );
    push( &head, 5 );

    push( &( head->right ), 20 );
    push( &( head->right ), 10 );

    push( &( head->right->right ), 50 );
    push( &( head->right->right ), 22 );
    push( &( head->right->right ), 19 );

    push( &( head->right->right->right ), 45 );
    push( &( head->right->right->right ), 40 );
    push( &( head->right->right->right ), 35 );
    push( &( head->right->right->right ), 20 );

    // Let us flatten the list
    head = flatten(head);

    // Let us print the flatened linked list
    printList(head);

    return 0;
}
