/*

I DID THIS ON MY OWN, DOING SLIGHT MODIFICATION ON TOP VIEW OF BINARY TREE CODE;
MODICATIONS -
1) FOR GETTING THE LAST VALUE THAT GETS ENTERED I ELIMINATED THE IF CONDITION PRESENT IN THE CODE OF TOP VIEW AND IT WORKED.

*/


//     https://www.geeksforgeeks.org/bottom-view-binary-tree/


{
// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
Node *newNode(int k)
{
    return new Node(k);
}
// Method that prints the bottom view.
void bottomView(Node *root);
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
struct Node
{
    int data; 
    Node *left, *right; 
}; */
// Method that prints the bottom view.
void bottomView(Node *root)
{
   // Your Code Here
   
   struct Node * temp = NULL;
   queue <pair<struct Node *, int>> q;
   map <int,int> m;
   
   q.push({root,0});
   
   while(!q.empty()){
       temp = q.front().first;
       int d = q.front().second;
       q.pop();
       
                              //     <<----- HERE THERE WAS AN IF CONDITION IN TOP VIEW OF BINARY TREE CODE
       m[d] = temp->data;
       
       if(temp->left){
           q.push({temp->left,d-1});
       }
       if(temp->right){
           q.push({temp->right,d+1});
       }
   }
   
   for(auto x = m.begin(); x != m.end(); x++){
       cout<<(x->second)<<" ";
   }
   
}
