// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0


#include <iostream>
using namespace std;

int main() {
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
	    
	    int index1 = 0;
	    int index2 = 1;
	    int d = a[index1];
	    
	    while(index1 < n && d != sum){
	        if(d < sum){
	            d = d + a[index2];
	            index2++;
	        }else if(d > sum){
	            d = d - a[index1];
	            index1++;
	        }
	    }
	    if(d == sum){
	        index1++;
	        cout<<index1<<" "<<index2<<endl;
	        continue;
	    }
	    if((index1 >= n || index2 >= n)){
	        cout<<"-1 "<<endl;
	    }
	    
	}
	
	return 0;
}
