//    https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1

{
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
void printPaths(struct Node *root);
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void inorder(struct Node* root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin>>t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin>>n;
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     printPaths(root);
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 #include<bits/stdc++.h>
 
 
 
 void print(struct Node * r, int v[], int len){
     if(!r){
         return ;
     }
     v[len] = (r->data);
     len++;
     if(!r->left && !r->right){
         for(int i=0;i<len;i++){
             cout<<v[i]<<" ";
         }
         cout<<"#";
     }
     
     print(r->left,v,len);
     print(r->right,v,len);
 }
 
void printPaths(Node* root)
{
    // Code here
    int v[1000];
    print(root,v,0);
    cout<<endl;
    
}
