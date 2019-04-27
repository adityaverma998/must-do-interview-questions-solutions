//    https://www.geeksforgeeks.org/level-order-traversal-in-spiral-form/

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
void printSpiral(struct Node *root);
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
    printSpiral(root);
    cout<<endl;
  }
    return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void printSpiral(Node *root)
{
     //Your code here
     
     stack <struct Node *> s1;
     stack <struct Node *> s2;
     
     s1.push(root);
     
     while(!s1.empty() || !s2.empty()){
         
         while(!s1.empty()){
             struct Node * temp = s1.top();
             s1.pop();
             cout<<temp->data<<" ";
             if(temp->right){
                 s2.push(temp->right);
             }
             if(temp->left){
                 s2.push(temp->left);
             }
         }
         
         while(!s2.empty()){
             struct Node * temp = s2.top();
             s2.pop();
             cout<<temp->data<<" ";
             if(temp->left){
                 s1.push(temp->left);
             }
             if(temp->right){
                 s1.push(temp->right);
             }
         }
     }
     
}
