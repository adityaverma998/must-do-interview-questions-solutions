/*

O(n^2) approach but this has worked on online compiler, their is a better approach too using hashing O(n).

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
	    int sum;
	    cin>>sum;
	    
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    int count = 0;
	    for(int j=0;j<n;j++){
	        for(int k=j+1;k<n;k++){
	            if(a[j] + a[k] == sum){
	                ++count;
	            }
	        }
	    }
	    
	    cout<<count<<endl;
	}
	
	return 0;
}
