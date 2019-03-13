/*


https://practice.geeksforgeeks.org/problems/binary-array-sorting/0

*/






#include<bits/stdc++.h>
using namespace std;
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
	    
	    int zeros = 0;
	    int ones = 0;
	    for(int j=0;j<n;j++){
	        if(a[j] == 0){
	            ++zeros;
	        }
	        if(a[j] == 1){
	            ++ones;
	        }
	    }
	    for(int j = 0; j <zeros;j++){
	        cout<<"0 ";
	    }
	    for(int j = 0; j <ones;j++){
	        cout<<"1 ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
