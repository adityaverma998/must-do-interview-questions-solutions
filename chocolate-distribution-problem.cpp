#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    sort(a,a+n);
	    
	    int k;
	    cin>>k;
	    
	    int min = 100000;
	    
	    if(k == n){
	        min = a[n-1] - a[0];   
	    }
	    
	    for(int j=0;j+k-1<n;j++){
	        if(a[j+k-1] - a[j] < min){
	            min = a[j+k-1] - a[j];
	        }
	    }
	    
	    cout<<min<<endl;
	    
	}
	
	return 0;
}
