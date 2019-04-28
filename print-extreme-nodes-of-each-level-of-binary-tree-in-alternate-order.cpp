//   https://www.geeksforgeeks.org/print-extreme-nodes-of-each-level-of-binary-tree-in-alternate-order/

//  https://youtu.be/0mR5XScq3iI


{
/* C++ program to print nodes of extreme corners
of each level in alternate order */
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    Node *left, *right;
};
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root);
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
   printExtremeNodes(root);
   cout<<endl;
  }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
 A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root)
{
    // Your code here
    
    if(!root){
        return ;
    }
    
    queue < Node * > q;
    q.push(root);
    
    bool flag = false;
    
    while(!q.empty()){
        int nodecount = q.size();
        int n = nodecount;
        
        while(n--){
            struct Node * temp = q.front();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
            q.pop();
            
            if(flag && n == nodecount-1){
                cout<<temp->data<<" ";
            }
            if(!flag && n == 0){
                cout<<temp->data<<" ";
            }
        }
        flag = !flag;
    }
    
}
