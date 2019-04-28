//   https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

{
/* program to construct tree using inorder and postorder traversals */
#include<bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
  int data;
  Node* left;
  Node* right;
};
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node)
{
  if (node == NULL)
     return;
   /* then print the data of node */
  printf("%d ", node->data);
  /* first recur on left child */
  preOrder(node->left);
  /* now recur on right child */
  preOrder(node->right);
}
Node *buildTree(int in[], int post[], int n);
int main()
{
	int t,n;
	cin>>t;
	int in[1000], post[1000];
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>in[i];
		for(int i=0;i<n;i++)
			cin>>post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
		cout<<endl;
	}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node structure
struct Node 
{
   int data;
   Node *left, *right;
}*/
// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays

struct Node * newnode(int d){
    struct Node * nn = (struct Node *)malloc(sizeof(struct Node *));
    nn->data = d;
    nn->left = nn->right = NULL;
    return nn;
}

struct Node * bt(int in[],int post[],int s,int e,unordered_map <int,int> &m, int * pt){
    if(s>e){
        return NULL;
    }
    int cur = post[(*pt)--];
    struct Node * temp = newnode(cur);
    if(s == e){
        return temp;
    }
    int index = m[cur];
    
    temp->right = bt(in,post,index+1,e,m,pt);
    temp->left = bt(in,post,s,index-1,m,pt);
    
    
    return temp;
}

Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    
    unordered_map < int, int > m;
    
    for(int i=0;i<n;i++){
        m.insert(make_pair(in[i],i));
    }
    int postin = n-1;
    return bt(in,post,0,n-1,m,&postin);
    
}
