/*

https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
*/


#include<bits/stdc++.h>

using namespace std;


int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int p;
	    cin>>p;
	    int q;
	    cin>>q;
	    int a[p][q];
	    
	    for(int j=0;j<p;j++){
	        for(int k=0;k<q;k++){
	            cin>>a[j][k];
	        }
	    }
	    int m = p;
	    int n = q;
	    int  k=0, l=0;
    
    while(k < m && l < n){
        
        for(int i=l;i<n;i++){
            cout<<a[k][i]<<" ";
        }
        k++;
        
        for(int i=k;i<m;i++){
            cout<<a[i][n-1]<<" ";
        }
        n--;
        
        if(k<m){
            for(int i = n-1;i>=l;i--){
                cout<<a[m-1][i]<<" ";
            }
            m--;
        }
        
        if(l<n){
            for(int i = m-1;i>=k;i--){
                cout<<a[i][l]<<" ";
            }
            l++;
        }
        
    }
	    
	    cout<<endl;
	}
	
	return 0;
}
