//http://eclassesbyravindra.com/mod/page/view.php?id=3548

//https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

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
	    int sum;
	    cin>>sum;
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    int left = 0;
	    int right = 0;
	    int cur_sum = a[0];
	    
	    while(cur_sum != sum && left < n && right < n){
	        if(cur_sum < sum){
	            right++;
	            cur_sum = cur_sum + a[right];
	        }
	        if(cur_sum > sum){
	            cur_sum = cur_sum - a[left];
	            left++;
	        }
	    }
	    
	    if(cur_sum != sum){
	            cout<<"-1"<<endl;
	    }else{
	        
	        cout<<left+1<<" "<<right+1<<endl;
	    }
	    
	}
	
	return 0;
}
