// https://www.geeksforgeeks.org/print-nodes-distance-k-leaf-node/

{
/* Program to print all nodes which are at distance k from a leaf */
#include<bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 10000
struct Node
{
	int key;
	Node *left, *right;
};
/* utility that allocates a new Node with the given key */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}
int printKDistantfromLeaf(Node* node, int k);
 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=newNode(n2);
                    break;
          case 'R': root->right=newNode(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=newNode(n1);
            switch(lr){
                    case 'L': root->left=newNode(n2);
                    break;
                    case 'R': root->right=newNode(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
    cin>>k;
    cout<<printKDistantfromLeaf(root, k)<<endl;
    }
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//Node Structure
/*struct Node
{
	int key;
	Node *left, *right;
};*/
//This function returns the count of the total distinct nodes that are at a 
//distance k from leaf nodes.
int countt = 0;

void print(int path[], int visited[], struct Node * r,int k,int no){
    if(!r){
        return;
    }
    path[no] = r->key;
    visited[no++] = 0;
    if(!r->left && !r->right && no - k - 1 >= 0 && visited[no-k-1] != 1){
        visited[no-k-1] = 1;
        ++countt;
        return;
    }
    print(path,visited,r->left,k,no);
    print(path,visited,r->right,k,no);
}

int printKDistantfromLeaf(Node* node, int k)
{
	//Add your code here. 
	
	int path[10000];
	int visited[10000];
	
	print(path,visited,node,k,0);
	int x = countt;
	countt = 0;
	return x;
}
