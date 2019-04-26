/*

https://www.geeksforgeeks.org/print-left-view-binary-tree/

https://www.geeksforgeeks.org/iterative-method-to-print-left-view-of-a-binary-tree/


*/



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
// A wrapper over leftViewUtil()
void leftView(struct Node *root);
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
     leftView(root);
     cout << endl;
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
// A wrapper over leftViewUtil()



void leftView(Node *root)
{
   // Your code here
   
   queue <Node *> q;
   
   q.push(root);
   
   q.push(NULL);
   
   while(!q.empty()){
       if(q.front()){
           
       
       cout<<q.front()->data<<" ";
       
       while(q.front() != NULL){
           
           if(q.front()->left){
               q.push(q.front()->left);
           }
           if(q.front()->right){
               q.push(q.front()->right);
           }
            q.pop();
       }
       
       q.push(NULL);
       
       }
       
       
       q.pop();
   }
   
   
   
}
