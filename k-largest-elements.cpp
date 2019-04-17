//    https://practice.geeksforgeeks.org/problems/k-largest-elements/0#_=_

#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){
    
        return a>b;
    
};

int main()
 {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	        
	    }
	    
	    sort(a,a+n,compare);
	    for(int j=0;j<k;j++){
	        cout<<a[j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
