//   https://www.geeksforgeeks.org/find-number-zeroes/



#include<iostream>
using namespace std;

int firstindex(int a[], int s, int e){
    if(s<=e){
        int mid = (s+e)/2;
        if((mid == 0 || a[mid-1] == 1) && a[mid] == 0){
            return mid;
        }
        if(a[mid] == 1){
            return firstindex(a,mid+1,e);
        }else{
            return firstindex(a,s,mid-1);
        }
    }
    return -1;
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
	    
	    int index = firstindex(a,0,n-1);
	    
	    // n - index
	    
	    if(index == -1){
	        cout<<"0"<<endl;
	    }else{
	        cout<<(n-index)<<endl;
	    }
	    
	    
	}
	
	return 0;
}
