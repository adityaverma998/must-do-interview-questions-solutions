//  https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/

// read BELOW THERE IS MAP UPDATION BEING DONE USING PASSING BY ADDRESS 


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
void verticalOrder(Node *root);
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
     verticalOrder(root);
     cout << endl;
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

void inorderr(struct Node * r, int ht, map<int, vector<int> > &m){   // <<<<------- SEE HERE ---- MAP PASSED THROUGH ADDRESS TO UPDATE THE VALUES IN MAP
    if(r == NULL){
        return ;
    }
    
    m[ht].push_back(r->data);
    
    inorderr(r->left,(ht-1),m);
    inorderr(r->right,(ht+1),m);
}

void verticalOrder(Node *root)
{
    //Your code here
    
    
    map < int, vector<int> > m;
    int ht = 0;
    inorderr(root,ht,m);
    
    for(auto it = m.begin(); it != m.end(); it++){
        
        for(auto x = it->second.begin(); x != it->second.end(); x++){
            cout<<*x<<" ";
        }
        
    }
    
}
