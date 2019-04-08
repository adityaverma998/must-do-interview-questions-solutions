//  https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

// http://eclassesbyravindra.com/mod/page/view.php?id=3281


{
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
 Node* insert(Node* head, int data)
{
    if (head == NULL)
        head = newNode(data);
    else
        head->next = insert(head->next, data);
    return head;
}
 void makeLoop(Node* head, int x)
{
    if (x == 0)
        return;
    Node* curr = head;
    Node* last = head;
    int counter = 0;
    while (counter < x)
    {
        curr = curr->next;
        counter++;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}
 int detectloop(Node* head)
{
    Node* hare = head->next;
    Node* tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL)
    {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;
        if (hare == tortoise)
            return 1;
    }
    if (hare == tortoise)
        return 1;
    return 0;
}
 int length(Node* head, bool hasloop)
{
    int len = 0;
    if (hasloop == false)
    {
        Node* temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    else
    {
        Node* hare = head->next;
        Node* tortoise = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;
            if (hare == tortoise)
                break;
        }
       
        int looplen = 0;
        while (hare->next!=tortoise)
        {
            hare = hare->next;
            looplen++;
        }
        
        looplen++;
        Node* begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise)
        {
            
            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;
        }
        
        return looplen + startlen;
        
    }
}
//Position this line where user code will be pasted.
int main() {
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *head=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        for(int i=0;i<sizeOfArray;i++)
        {
            cin>>arr[i];
            head=insert(head,arr[i]);
            
        }
        int x;
        cin>>x;
        makeLoop(head,x);
        int lengthll=0;
        if(detectloop(head)==1)
        lengthll=length(head,true);
        else
        lengthll=length(head,false);
        
        removeTheLoop(head);
        
        if (detectloop(head) == 0 && lengthll == length(head, false))
        {
            cout<<1<<endl;
        }
        else
        cout<<0<<endl;
    }
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
     //Your code here
     
     struct Node * s = head;
     struct Node * f = head;
     if(!head){
         return;
     }
     while(s && f && f->next){
         s = s->next;
         f = f->next->next;
         if(s == f){
             break;
         }
     }
     if(!s || !f || !f->next){
         return;
     }
     s = head;
     
     while(s && f && f->next){
         s = s->next;
         f = f->next;
         if(s == f){
             break;
         }
     }
     f = f->next;
     while(s && f && f->next && f->next != s){
         f = f->next;
     }
     
     f->next = NULL;
     return;
}
