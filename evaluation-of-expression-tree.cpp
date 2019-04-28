//   https://www.geeksforgeeks.org/evaluation-of-expression-tree/

{
#include<bits/stdc++.h>
using namespace std;
struct node{
	string data;
	node *left;
	node *right;
};
int evalTree(node *);
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
	string s[n];
	for(int i=0;i<n;i++)
		cin>>s[i];
	int p=0;
	node *root = new node;
	root->data = s[p];
	root->left=NULL;
	root->right=NULL;
	queue<node *> q;
	q.push(root);
    p=1;
	while(!q.empty())
	{
		node *f = q.front();
		q.pop();
		node  *l,*r;
		if(p!=n){
        l=new node;
		l->data = s[p];
		f->left = l;
		p++;
		q.push(l);
	    }
	    else
	    {
	    	f->left = NULL;
	    }
		if(p!=n){
        r=new node;
		r->data = s[p];
		f->right = r;
		p++;
		q.push(r);
		}else
		{
			f->right=NULL;
		}
	}
	cout<<evalTree(root)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/
/*You are required to complete below method */
#include <bits/stdc++.h>

int evalTree(node* root)
{
    //Your code here
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return (stoi(root->data));
    }
    int left = evalTree(root->left);
    int right = evalTree(root->right);
    
    if(root->data=="+"){
        return left + right;
    }
    if(root->data=="-"){
        return left - right;
    }
    if(root->data=="*"){
        return left * right;
    }
    if(root->data=="/"){
        return left / right;
    }
}
