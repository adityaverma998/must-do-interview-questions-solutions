#include <bits/stdc++.h>

struct Node * newnode(int x){
    struct Node * nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = x;
    nn->next = NULL;
    return nn;
}

Node* sortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    
    priority_queue <int,vector<int> , greater<int> > q;
    struct Node * temp = head1;
    while(temp){
        q.push(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        q.push(temp->data);
        temp = temp->next;
    }
    
    struct Node * h = NULL;
    struct Node * t = NULL;
    
    while(!q.empty()){
        int no = q.top();
        q.pop();
        if(!h){
            h = newnode(no);
            t = h;
        }else{
            t->next = newnode(no);
            t = t->next;
        }
    }
    
    return h;
}
