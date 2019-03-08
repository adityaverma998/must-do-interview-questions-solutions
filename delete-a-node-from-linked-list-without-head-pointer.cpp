/*


https://www.geeksforgeeks.org/delete-a-node-from-linked-list-without-head-pointer/



For example, suppose we need to delete C and a pointer to C is given. If we had a pointer to B we could have deleted C easily. But here we will copy the data field of D to data field of C. Then we will move forward. Now we are at D and we have a pointer to C i.e. the previous pointer. So we will delete D. That’s how the node C will be deleted.

filter_none
edit
play_arrow

brightness_4
void deleteNodeWithoutHead(struct Node* pos) 
{ 
    if (*pos == NULL) // If linked list is empty 
        return; 
  
    else { 
        struct Node* temp = pos->next; 
  
        // Copy data of the next node to current node 
        pos->data = pos->next->data;  
  
        // Perform conventional deletion 
        pos->next = pos->next->next;  
  
        free(temp); 
    } 
    return 0; 
} 


*/



{
#include<bits/stdc++.h>
using namespace std;
/* Link list node */
struct Node
{
    int data;
    Node* next;
}*head;
Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}
void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(Node *) malloc( sizeof(Node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (Node *) malloc( sizeof(Node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
void deleteNode(Node *node_ptr);
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
        Node *del = findNode(head, k);
        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    }
    return(0);
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Link list node 
struct Node
{
    int data;
    Node* next;
}*/
// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
void deleteNode(Node *node)
{
   // Your code here
   
   struct Node * t = node;
   
   t->data = t->next->data;
   
   t->next = t->next->next;
   
   
   
   
}
