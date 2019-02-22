/*

https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0


*/


#include <iostream>
using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    int p = 0;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    int k ;
	    for(int j=0;j<n;j++){
	        k = j + 1;
	        while(a[k-1] < a[k] && k < n){
	            k++;
	        }
	        /*if(a[k-1]>=a[k])*/
	            if(j != k-1){
	                cout<<"("<<j<<" "<<k-1<<")"<<" ";
	                p=1;
	            }
	        
	        j=k-1;
	    }
	    if(p == 0){
	        cout<<"No Profit";
	    }
	    cout<<endl;
	}
	
	
	return 0;
}
