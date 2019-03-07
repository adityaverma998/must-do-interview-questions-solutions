/*

dont use gfg method for this question instead look at the code 


https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
*/




{
#include <bits/stdc++.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};
using namespace std;
void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
Node* flatten (Node* root);
int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		   /*
		while(fun!=NULL)
            {
                cout<<fun->data<<" ";
                fun2 = fun->bottom;
                fun=fun->next;
                while(fun2){
                cout<<fun2->data<<" ";
                fun2=fun2->bottom;
                }
                cout<<endl;
            }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */

Node * insert(struct Node * r, int ele){
    struct Node * nn = (struct Node *)malloc(sizeof(struct Node));
    nn->data = ele;
    nn->next = NULL;
    nn->bottom = NULL;
    if(r == NULL){
        r = nn;
        return r;
    }
    struct Node * t = r;
    while(t->bottom){
        t = t->bottom;
    }
    t->bottom = nn;
    return r;
}

Node *flatten(Node *root)
{
   // Your code here
   
   
   vector <int> v;
   
   struct Node * temp1 = root;
   
   while(temp1 != NULL){
       struct Node * temp2 = temp1;
       while(temp2 != NULL){
            v.push_back(temp2->data);  
            temp2 = temp2->bottom;
       }
       temp1 = temp1->next;
   }
   
   sort(v.begin(),v.end());
   struct Node * r = NULL;
   for(auto i = v.begin(); i != v.end(); i++){
       int ele = *i;
       r = insert(r,ele);
   }
   return r;
}
