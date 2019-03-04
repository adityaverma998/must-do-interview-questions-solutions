/*

https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1


*/



{
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head;
void rotate(struct node **head_ref, int k);
  void insert()
{
    int n,i,value;
    struct node *temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,n,value;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     rotate(&head,k);
     printList(head);
     }
     return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Rotate a linked list after node k
  The input list will have at least one element  
  A Linked List node has following structure.
  struct node
  {
     int data;
     struct node *next;
  }
*/
/*  **head_ref is a pointer to head pointer.  This function
    should modify value at head_ref to change head (if required)*/
void rotate(struct node **head_ref, int k)
{
    if(*head_ref == NULL){
        return ;
    }
    
    int size = 0;
    struct node * sz = * head_ref;
    while(sz != NULL){
        ++size;
        sz = sz->next;
    }
    if(size == k){
        return;
    }
    
    struct node * x = *head_ref;
    struct node * y = NULL;
    while(k != 0 && x->next != NULL){
        --k;
        y = x;
        x = x->next;
    }
    y->next = NULL;
    struct node * end = x;
    while(end->next != NULL){
        end = end->next;
    }
    end->next = *head_ref;
    *head_ref = x;
    return;
}
