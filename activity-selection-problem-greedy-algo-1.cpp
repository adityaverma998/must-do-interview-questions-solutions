//    https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

#include<bits/stdc++.h>

using namespace std;

struct node{
    int s;
    int f;
    int index;
};

bool compare(struct node a, struct node b){
    return (a.f < b.f);
}

int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    struct node a[n];
	    
	    for(int j=0;j<n;j++){
	        cin>>(a[j].s);
	    }
	    for(int j=0;j<n;j++){
	        cin>>(a[j].f);
	        (a[j].index) = j+1;
	    }
	    
	    
	    sort(a,a+n,compare);
	    
	    int x=0;
	    cout<<a[x].index<<" ";
	    
	    for(int j=1;j<n;j++){
	        if(a[x].f <= a[j].s){
	            cout<<a[j].index<<" ";
	            x = j;
	        }
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
