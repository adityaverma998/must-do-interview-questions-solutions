//array section rbr 

//   https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    int yes = 0;
	    int sum;
	    cin>>n;
	    cin>>sum;
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    sort(a,a+n);
	    
	    for(int i1=0;i1<n;i1++){
	        int i2 = i1 + 1;
	        int i3 = n-1;
	        
	        while(i2 < i3){
	            if(a[i1] + a[i2] + a[i3] == sum){
	                yes = 1;
	                break;
	            }
	            if(a[i1] + a[i2] + a[i3] > sum){
	                i3--;
	            }
	            if(a[i1] + a[i2] + a[i3] < sum){
	                i2++;
	            }
	        }
	        if(yes == 1){
	            break;
	        }
	    }
	    
	    if(yes == 1){
	        cout<<"1"<<endl;
	    }else{
	        cout<<"0"<<endl;
	    }
	}
	
	return 0;
}
