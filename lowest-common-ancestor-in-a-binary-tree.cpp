// must watch before doing --- >>>>    https://www.youtube.com/watch?v=F-_1sbnPbWQ
  
// LCA in binary tree and bst have different codes   
  
{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
Node * LCA(Node* ,int ,int );
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
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
     int a,b;
     cin>>a>>b;
     Node * k = LCA(root,a,b);
     cout<<k->data<<endl;
  }
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
/*you are required to 
complete this function */
Node * LCA(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   
   if(!root){
       return root;
   }
   
   if(root->data == n1 || root->data == n2){
       return root;
   }
   
   root->left = LCA(root->left,n1,n2);
   root->right = LCA(root->right,n1,n2);
   
   if(root->left != NULL && root->right != NULL){
       return root;
   }else{
       return (root->left?root->left:root->right);
   }
}
