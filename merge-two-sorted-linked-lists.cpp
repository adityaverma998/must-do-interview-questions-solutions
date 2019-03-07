/*

https://www.youtube.com/watch?v=j_UNYW6Ap0k      <<<<<<------- watch this

https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1


*/




{
// C program to find n'th Node in linked list
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node* SortedMerge(struct Node* a, struct Node* b);
void MoveNode(struct Node** destRef, struct Node** sourceRef);
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
/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;
        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = SortedMerge(head1, head2);
        printList(head);
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
Node* SortedMerge(Node* head1, Node* head2)
{
    // Your Code Here
    
    struct Node * s = NULL;
    
    struct Node * temp1 = head1;
    struct Node * temp2 = head2;
    if(temp1->data < temp2->data){
        s = temp1;
        temp1 = temp1->next;
    }else{
        s = temp2;
        temp2 = temp2->next;
    }
    struct Node * h = s;
    
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->data < temp2->data){
            s->next = temp1;
            s = s->next;
            temp1 = temp1->next;
        }else{
            s->next = temp2;
            s = s->next;
            temp2 = temp2->next;
        }
    }
    
    if(temp1 == NULL){
        s->next = temp2;
    }
    if(temp2 == NULL){
        s->next = temp1;
    }
    return h;
}
