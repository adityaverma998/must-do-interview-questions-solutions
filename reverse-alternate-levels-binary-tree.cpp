//          http://eclassesbyravindra.com/mod/page/view.php?id=6314

//        https://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/



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
// The main function to reverse alternate Nodes of a binary tree
void reverseAlternate(struct Node *root);
// A utility function to print indorder traversal of a
// binary tree
void printInorder(struct Node *root)
{
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
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
   reverseAlternate(root);
   printInorder(root);
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

void swapno(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void rev(struct Node * r, struct Node * t,int l){
    if(!r || !t){
        return ;
    }
    if(l%2 == 0){
        int temp1 = r->data;
        int temp2 = t->data;
        t->data = temp1;
        r->data = temp2;
    }
    rev(r->left,t->right,l+1);
    rev(r->right,t->left,l+1);
}
void reverseAlternate(Node *root)
{
    //Your code here
    
    rev(root->left,root->right,0);
    return;
}
