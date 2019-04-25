//   https://practice.geeksforgeeks.org/problems/vertical-sum/1


{
#include<bits/stdc++.h>
using namespace std;
struct Node{
int data;
Node *left,*right;
};
Node *newNode(int data){
	Node *a=new Node;
	a->data=data;
	a->left=a->right=NULL;
	return a;
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
int mn=0;
int aa[10000];
void printVertical(Node *root);
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(aa,0,sizeof(aa));
		int n;
		cin>>n;
		mn=0;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2;
			scanf(" %c",&lr);
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
					break;
					case 'R':root->right=newNode(a2);
					break;
				}
			}
			else{
				insert(root,a1,a2,lr);
			}
		}
		printVertical(root);
		cout<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/

void inorderr(struct Node * r, int hd, map<int , vector <int> > &m){
    if(!r){
        return;
    }
    m[hd].push_back(r->data);
    inorderr(r->left,hd-1,m);
    inorderr(r->right,hd+1,m);
}

void printVertical(Node *root)
{
//add code here.

    map<int , vector<int>> m;
    
    int hd=0;
    inorderr(root,hd,m);
    
    for(auto it = m.begin(); it != m.end(); it++){
        int sum = 0;
        for(auto x = it->second.begin(); x != it->second.end(); x++){
            sum = sum + *x;
        }
        cout<<sum<<" ";
    }

}
