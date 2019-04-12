//  https://www.geeksforgeeks.org/merge-sort-for-linked-list/


{
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
struct node* mergeList(struct node* a, struct node* b);
void splitList(struct node* source, struct node** frontRef, struct node** backRef);
void mergeSort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a;
    struct node* b;
    if ((head == NULL) || (head->next == NULL))return;
    splitList(head, &a, &b); 
    mergeSort(&a);
    mergeSort(&b);
    *headRef = mergeList(a, b);
}
void printList(struct node *node)
{
    while(node!=NULL){
        printf("%d ", node->data);
        node = node->next;
    }
    printf("
");
}
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref); 
    (*head_ref) = new_node;
} 
int main()
{
    long test;
    cin>>test;
    while(test--)
    {
        struct node* a = NULL;
        long n, tmp;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp;
            push(&a, tmp);
        }
        mergeSort(&a);
        printList(a);
    }
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of the linked list node is as
struct node
{
	int data;
	struct node* next;
};
*/
/* split the nodes of the given list into front and back halves,
     and return the two lists using the reference parameters.*/
void splitList(struct node* source, struct node** frontRef, struct node** backRef)
{
    // Code here
    
    struct node * slow;
    struct node * fast;
    
    slow = source;
    fast = source->next;
    
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
    
}
// merges two sorted list into one big list
struct node* mergeList(struct node* a, struct node* b)
{
    // Code here
    
    struct node * result = NULL;
    
    if(!a){
        return b;
    }else if(!b){
        return a;
    }
    
    if(a->data <= b->data){
        result = a;
        result->next = mergeList(a->next,b);
    }else{
        result = b;
        result->next = mergeList(a,b->next);
    }
    
    return result;
}
