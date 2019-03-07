/*


search for gfg post on this topic <<<<<<<<----------

https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/


algo used - 

Method 3(Using difference of node counts)
1) Get count of the nodes in the first list, let count be c1.
2) Get count of the nodes in the second list, let count be c2.
3) Get the difference of counts d = abs(c1 – c2)
4) Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes.
5) Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

*/






{
#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
int intersectPoint(struct Node* head1, struct Node* head2);
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
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
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
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    
    struct Node * t = head1;
    int no1 = 0;
    while(t){
        ++no1;
        t = t->next;
    }
    int no2 = 0;
    t = head2;
    while(t){
        ++no2;
        t = t->next;
    }
    t = NULL;
    
    int diff = abs(no1 - no2);
    int y = 0;
    if(no1 > no2){
        t = head1;
        y = 1;
    }else{
        t = head2;
    }
    
    while(diff){
        --diff;
        t = t->next;
    }
    if(y == 1){
        struct Node * t2 = head2;
        while(t2 != t && t2 && t){
            t2 = t2->next;
            t = t->next;
        }
        if(t2 == NULL || t == NULL){
            return -1;
        }
    }else{
        struct Node * t2 = head1;
        while(t2 != t && t2 && t){
            t2 = t2->next;
            t = t->next;
        }
        if(t2 == NULL || t == NULL){
            return -1;
        }
    }
    
    
    
    return (t->data);
}
