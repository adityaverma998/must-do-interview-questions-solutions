/*

https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1

*/





{
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
bool isPalindrome(Node *head);
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
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/
/*You are required to complete this method */

void reverse(struct Node ** head){
    struct Node * prev = NULL;
    struct Node * cur = *head;
    struct Node * nex = NULL;
    
    while(cur != NULL){
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }
    
    *head = prev;
}

bool isPalindrome(Node *head)
{
    //Your code here
    
    struct Node * temp = head;
    int size = 0;
    while(temp != NULL){
        ++size;
        temp = temp->next;
    }
    
    int a[size];
    
    temp = head;
    int index = 0;
    while(temp != NULL){
        a[index++] = temp->data;
        temp = temp->next;
    }
    
    temp = head;
    reverse(&head);
    struct Node * t = head;
    int i = 0;
    int x = 1;
    while(t != NULL && i < index){
        if(a[i++] != t->data){
            
            x = 0;
            break;
        }
        t = t->next;
    }
    reverse(&head);
    if(x == 0){
        return 0;
    }else{
        return 1;
    }
    
    
}
