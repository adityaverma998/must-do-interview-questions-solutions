//  https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0


#include <iostream>
using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
	    int n;
	    cin>>n;
	    int k;
	    cin>>k;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<=n-k;i++){
	        int max = -1000;
	        for(int l=i;l<i+k;l++){
	            if(max < a[l]){
	                max = a[l];
	            }
	        }
	        cout<<max<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
