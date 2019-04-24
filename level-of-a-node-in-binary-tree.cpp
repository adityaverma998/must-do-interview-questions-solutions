//    https://practice.geeksforgeeks.org/problems/level-of-a-node-in-binary-tree/1


{
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
int getLevel(struct Node *node, int target);
struct Node* newNode(int data)
{
	struct Node *temp = new struct Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
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
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a;
     cin>>a;
    cout<<getLevel(root, a)<<endl;
  }
  }
  return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node


int max(int a, int b){
    if(a>b){
        return a;
    }
    return b;
}

int getLevel(struct Node *node, int target)
{
	//code here
	
	if(node == NULL){
	    return INT_MIN;
	}
	if(node->data == target){
	    return 1;
	}
	return (1 + max(getLevel(node->left,target) , getLevel(node->right,target)));
}
