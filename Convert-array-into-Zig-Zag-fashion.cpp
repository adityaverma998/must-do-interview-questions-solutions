/*

https://practice.geeksforgeeks.org/problems/convert-array-into-zig-zag-fashion/0
*/


#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
 {
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
	    
	    if(n%2 == 0){
	        for(int j = 1;j<=n-3;j = j+2){
	            if(a[j-1] > a[j]){
	            swap(a[j-1],a[j]);
	        }
	        if(a[j+1]>a[j]){
	            swap(a[j+1],a[j]);
	        }
	        }
	        
	        if(a[n-1] < a[n-2]){
	            swap(a[n-1],a[n-2]);
	        }
	        for(int j=0;j<n;j++){
	            cout<<a[j]<<" ";
	        }
	        
	    }
	    
	    if(n%2 != 0){
	    
	    for(int j=1;j<n-1;(j = j+2)){
	        if(a[j-1] > a[j]){
	            swap(a[j-1],a[j]);
	        }
	        if(a[j+1]>a[j]){
	            swap(a[j+1],a[j]);
	        }
	    }
	    
	    for(int j=0;j<n;j++){
	        cout<<a[j]<<" ";
	    }
	        
	    }
	    cout<<endl;
	}
	
	return 0;
}
