//  http://eclassesbyravindra.com/mod/page/view.php?id=4914

//  https://practice.geeksforgeeks.org/problems/trapping-rain-water/0



#include<bits/stdc++.h>
using namespace std;

int min(int x, int y){
    if(x < y){
        return x;
    }
    return y;
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
	    
	    int left[n];
	    int right[n];
	    int max = INT_MIN;
	    
	    for(int j=0;j<n;j++){
	        if(a[j] > max){
	            max = a[j];
	        }
	        left[j] = max;
	    }
	    
	    max = INT_MIN;
	    
	    for(int j=n-1;j>=0;j--){
	        if(a[j] > max){
	            max = a[j];
	        }
	        right[j] = max;
	    }
	    
	    for(int j=0;j<n;j++){
	        a[j] = min(left[j],right[j]) - a[j];
	    }
	    int sum = 0;
	    for(int j=0;j<n;j++){
	        sum = a[j] + sum;
	    }
	    cout<<sum<<endl;
	    
	}
	
	return 0;
}
