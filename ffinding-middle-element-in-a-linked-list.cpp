//   https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

{
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to get the middle of the linked list*/
int getMiddle(struct Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l;
    cin>>T;
    while(T--){
    struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
    printf("%d
", getMiddle(head));
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
   
   int no = 0;
   
   if(head == NULL){
       return 0;
   }
   struct Node * temp = head;
   
   while(temp){
       no++;
       temp = temp->next;
   }
   
   struct Node * t = head;
   
   if(no % 2 == 0){
       int x = (no/2) ;
       
       while( x ){
           x--;
           t = t->next;
       }
       return t->data;
   }else{
       int x = no/2;
       
       while(x){
           x--;
           t = t->next;
       }
       return t->data;
   }
   
}
