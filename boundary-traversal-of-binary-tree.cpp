// http://eclassesbyravindra.com/mod/page/view.php?id=6399

//   https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/


{
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* Node = (struct Node*)
                        malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
void printBoundary(Node *root);
int height(struct Node *root)
{
    if(root==NULL)
        return 0;
    int l = 1+height(root->left);
    int r=1+height(root->right);
    if(l>r)
        return l;
    else
        return r;
}
/* Driver program to test above functions*/
int main()
{
   int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        Node *child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
    printBoundary(root);
   cout<<endl;
  }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void printleft(struct Node * r){
    if(r){
    if(r->left){
        cout<<r->data<<" ";
        printleft(r->left);
    }else if(r->right){
        cout<<r->data<<" ";
        printleft(r->right);
    }}
}

void printleaves(struct Node * r){
    if(!r){
        return ;
    }
    printleaves(r->left);
    if(!r->left && !r->right){
        cout<<r->data<<" ";
    }
    printleaves(r->right);
}

void printright(struct Node * r){
    if(r){
    if(r->right){
        printright(r->right);
        cout<<r->data<<" ";
    }else if(r->left){
        printright(r->left);
        cout<<r->data<<" ";
    }
    }
}

void printBoundary(Node *root)
{
     //Your code here
     
     if(root){
         
         cout<<root->data<<" ";
         
         printleft(root->left);
         
         printleaves(root->left);
         printleaves(root->right);
         
         printright(root->right);
     }
     
}
