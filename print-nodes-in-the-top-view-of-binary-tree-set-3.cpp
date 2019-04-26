//    https://www.geeksforgeeks.org/print-nodes-in-the-top-view-of-binary-tree-set-3/

//    http://eclassesbyravindra.com/mod/page/view.php?id=3569



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
void topView(struct Node *root);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
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
     topView(root);
     cout << endl;
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//Structure of binary tree
/*struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/
// function should print the topView of the binary tree


void topView(struct Node *root)
{
    // Your code here
    
 if(!root){
        return ;
    }
    
    struct Node * temp = NULL;
    
    queue < pair < Node * , int > > q;
    map <int , int> m;
    
    q.push({root,0});
    
    while(!q.empty()){
        
        temp = q.front().first;
        int d = q.front().second;
        q.pop();
        
        if(m.find(d) == m.end()){
            cout<<temp->data<<" ";
            m[d] = temp->data;
        }
        
        if(temp->left){
            q.push({temp->left,d-1});
        }
        if(temp->right){
            q.push({temp->right,d+1});
        }
    }
}
