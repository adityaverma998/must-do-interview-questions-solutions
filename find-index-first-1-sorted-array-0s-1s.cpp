//     https://www.geeksforgeeks.org/find-index-first-1-sorted-array-0s-1s/



#include<iostream>
using namespace std;

int findfirstone(int a[], int s, int e){
    if(s<=e){
        int mid = (s+e)/2;
        if((mid == 0 || a[mid-1] == 0) && a[mid] == 1){
            return mid;
        }
        if(a[mid] == 0){
            return findfirstone(a,mid+1,e);
        }else{
            return findfirstone(a,s,mid-1);
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
	    
	    int index = findfirstone(a,0,n-1);
	    
	    cout<<index<<endl;
	}
	
	return 0;
}
