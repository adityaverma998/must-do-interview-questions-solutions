//   https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

{

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
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
Node* LCA(Node *root, int , int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        int l,r;
        cin>>l>>r;
        cout<<LCA(root,l,r)->data<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/
/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   
   if(!root){
       return NULL;
   }
   
   if(root->data < n1 && root->data < n2){
       if(root->right){
            return LCA(root->right,n1,n2);
       }else{
           return NULL;
       }
   }
   if(root->data > n1 && root->data > n2){
       if(root->left){
            return LCA(root->left,n1,n2);
       }else{
           return NULL;
       }
   }
   
   return root;
   
   
}
