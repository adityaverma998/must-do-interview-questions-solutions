// look for second approach - https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

// rbr video - http://eclassesbyravindra.com/mod/page/view.php?id=6402


{
#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
};
Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

struct Node * newnode(int c){
    struct Node * nn = (struct Node *)malloc(sizeof(struct Node *));
    nn->data = c;
    nn->left  = nn->right = NULL;
    return nn;
}

struct Node * bt(int in[], int pre[], int s, int e, unordered_map <int,int> &m, int * pindex){
    
    
    
    if(s>e){
        return NULL;
    }
    int ch = pre[(*pindex)++];
    struct Node * temp = newnode(ch);
    
    if(s == e){
        return temp;
    }
    
    int index = m[ch];
    
    temp->left = bt(in,pre,s,index-1,m,pindex);
    temp->right = bt(in,pre,index+1,e,m,pindex);
    
    return temp;
    
}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
//add code here.

unordered_map <int, int> m;

for(int i = inStrt; i <= inEnd; i++){
    m.insert(make_pair(in[i], i));
}
int pindex=0;
return bt(in,pre,inStrt,inEnd,m,&pindex);
}
