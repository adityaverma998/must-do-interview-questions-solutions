// http://eclassesbyravindra.com/mod/page/view.php?id=3298
// https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1



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
#include <bits/stdc++.h>

bool isPalindrome(Node *head)
{
    stack <int> s;
    struct Node * temp = head;
    
    while(temp){
        s.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    
    while(temp){
        if(temp->data == s.top()){
            temp = temp->next;
            s.pop();
        }else{
            return 0;
        }
    }
    
    return 1;
}
