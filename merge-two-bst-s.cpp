//    https://practice.geeksforgeeks.org/problems/merge-two-bst-s/1


{
//Code by 1shubhamjoshi1
#include<bits/stdc++.h>
using namespace std;
struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}
void merge(Node *root1,Node *root2);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root1;Node *root2;
        Node *tmp;
        root1 = NULL;
        root2=NULL;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root1, k);}
        for(int i=0;i<M;i++)
        {
            int k;
            cin>>k;
            insert(&root2, k);} 
       merge(root1,root2);
        cout<<endl;
    }
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of Node is
struct Node {
int data;
Node * right, * left;
};*/
/*You are required to complete below method */

#include <bits/stdc++.h>

vector <int> v;

void inorderr(struct Node * r){
    if(r){
        v.push_back(r->data);
        inorderr(r->left);
        inorderr(r->right);
    }
}

void inorder(struct Node * r){
    if(r){
        inorder(r->left);
        cout<<r->data<<" ";
        inorder(r->right);
    }
}

struct Node * newnode(int d){
    struct Node * x = (struct Node *)malloc(sizeof(struct Node *));
    x->data = d;
    x->left = x->right = NULL;
    return x;
}

struct Node * insertt(struct Node * r, int d){
    if(!r){
        return newnode(d);
    }
    if(d < r->data){
        r->left = insertt(r->left,d);
    }else if(d >= r->data){
        r->right = insertt(r->right,d);
    }
    return r;
}

void merge(Node *root1, Node *root2)
{
   //Your code here
   if(!root1 || !root2){
       return;
   }
   
   inorderr(root2);
   
   for(auto x = v.begin(); x != v.end(); x++){
       root1 = insertt(root1,*x);
   }
   
   inorder(root1);
   v.clear();
   
}
