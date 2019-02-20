//     https://practice.geeksforgeeks.org/problems/kth-smallest-element/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	
	for(int j=0;j<t;j++){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int k;
	    cin>>k;
	    sort(a,a+n);
	    cout<<a[k-1]<<endl;
	}
	
	return 0;
}
