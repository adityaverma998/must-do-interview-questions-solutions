/*

https://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

https://www.geeksforgeeks.org/check-binary-tree-subtree-another-binary-tree-set-2/

*/




{
#include <iostream>
#include <cstring>
#include<map>
using namespace std;
#define MAX 100
 
// Structure of a tree node
struct Node
{
    char key;
    struct Node *left, *right;
};
 
// A utility function to create a new BST node
Node *newNode(char item)
{
    Node *temp =  new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
bool isSubtree(Node *T, Node *S);
void storeInorder(Node *, char[], int&);
void storePreOrder(Node *, char[], int&);
 
// Driver program to test above function
int main()
{
     int t;
 
  scanf("%d", &t);
  while(t--)
  { struct Node *child=NULL;
     map<int, Node*> m;
     int n;
     scanf(" %d
",&n);
     struct Node *t2 = NULL;
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
           if (t2 == NULL)
             t2 = parent;
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
     struct Node *child1;
     map<int, Node*> m1;
     int nodes;
     scanf("%d
",&nodes);
     struct Node *t1 = NULL;
     while (nodes--)
     {
        Node *parent1;
        char lr1;
        int n3, n4;
        scanf("%d %d %c", &n3, &n4, &lr1);
        if (m1.find(n3) == m1.end())
        {
           parent1 = newNode(n3);
           m1[n3] = parent1;
           if (t1 == NULL)
             t1 = parent1;
        }
        else
           parent1 = m1[n3];
        child = newNode(n4);
        if (lr1 == 'L')
          parent1->left = child;
        else
          parent1->right = child;
        m1[n4]  = child;
     }
 
   cout<<isSubtree(t1,t2);
    cout<<"
";
  }
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A binary tree node
struct Node
{
    int key;
    Node* left, * right;
}; */
/*you are required to 
complete this function */

#include <bits/stdc++.h>

void inorderr(struct Node * r, vector <struct Node *> &v,int d){
    if(!r){
        return;
    }
    if(r->key == d){
        v.push_back(r);
    }
    inorderr(r->left,v,d);
    inorderr(r->right,v,d);
}

int isidentical(struct Node * r1, struct Node * r2){
    if(r1 == NULL && r2 == NULL){
        return 1;
    }
    if(r1 == NULL || r2 == NULL){
        return 0;
    }
    return ((r1->key == r2->key) && isidentical(r1->left,r2->left) && isidentical(r1->right,r2->right));
}



bool isSubtree(Node*  T1 ,Node * T2)
{
     //Your code here 
     //return 1 if T2 is subtree of T1 else 0
     
     int nodedata = T2->key;
     vector <struct Node *> where;
     inorderr(T1,where,nodedata);
     
     for(auto x = where.begin(); x != where.end(); x++){
         if(isidentical(T2,*x)){
             return 1;
         }
     }
     return 0;
}
