//   https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/



#include<bits/stdc++.h>
using namespace std;

struct node{
    char data;
    int freq;
    struct node * left;
    struct node * right;
};

struct node * newnode(char d, int f){
    struct node * nn = (struct node *)malloc(sizeof(struct node *));
    nn->data = d;
    nn->freq = f;
    nn->left = nn->right = NULL;
    return nn;
}
struct compare{
    bool operator()(struct node * a, struct node * b){
        return (a->freq > b->freq);
    }
};

void printcode(struct node * x, string s){
    if(!x){
        return;
    }
    if(x->data != '$'){
        cout<<s<<" ";
    }
    printcode(x->left,s+"0");
    printcode(x->right,s+"1");
}

int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    string d;
	    vector <int> f;
	    
	    cin>>d;
	    int size = d.size();
	    
	    for(int j=0;j<size;j++){
	        int x;
	        cin>>x;
	        f.push_back(x);
	    }
	    
	    
	    struct node * left;
	    struct node * right;
	    struct node * top;
	    
	    priority_queue <struct node * , vector<struct node * > , compare> mh;
	    
	    for(int j=0;j<size;j++){
	        mh.push(newnode(d[j],f[j]));
	    }
	    
	    while(mh.size() != 1){
	        left = mh.top();
	        mh.pop();
	        right = mh.top();
	        mh.pop();
	        
	        top = newnode('$',(left->freq + right->freq));
	        top->left = left;
	        top->right = right;
	        
	        mh.push(top);
	    }
	    
	    printcode(mh.top(),"");
	    
	    cout<<endl;
	}
	
	return 0;
}
