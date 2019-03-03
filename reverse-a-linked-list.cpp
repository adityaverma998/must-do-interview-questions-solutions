/*

https://www.geeksforgeeks.org/reverse-a-linked-list/

*/



{
//Initial Template for C++
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
void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
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
struct Node *reverse(struct Node *head);
void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}
/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
       head = reverse(head);
       printList(head);
       cout << endl;
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
// Should reverse list and return new head.
struct Node* reverse(struct Node *head)
{
    
    if(head == '\0'){
        return NULL;
    }
  // Your code here
  struct Node * p = NULL;
  struct Node * c = head;
  struct Node * n = NULL;
  
  while(c!= NULL){
      
      n = c->next;
      c->next = p;
      p = c;
      c = n;
  }
  
  
  return p;
    
    
    
}
