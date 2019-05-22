//    https://www.geeksforgeeks.org/counting-inversions/




#include<iostream>
using namespace std;

long long int mergeprocedure(long long int a[], long long int temp[], long long int left, long long int mid, long long int right){
    long long int i,j,k;
    long long int count = 0;
    i = left;
    j = mid;
    k = left;
    
    while(i<=mid-1 && j<=right){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            count = count + (mid-i);
        }
    }
    
    while(i<=mid-1){
        temp[k++] = a[i++];
    }
    while(j<=right){
        temp[k++] = a[j++];
    }
    
    for(i = left; i<=right;i++){
        a[i] = temp[i];
    }
    return count;
}

long long int mergesort(long long int a[], long long int temp[], long long int left, long long int right){
    long long int mid, count=0;
    if(right>left){
        mid = (right+left)/2;
        count = mergesort(a,temp,left,mid);
        count += mergesort(a,temp,mid+1,right);
        count += mergeprocedure(a,temp,left,mid+1,right);
    }
    return count;
}

long long int merge(long long int a[], long long int n){
    long long int * temp = (long long int *)malloc(sizeof(long long int) * n);
    return mergesort(a,temp,0,n-1);
}

int main()
{
	//code
	
	long long int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    
	    long long int n;
	    cin>>n;
	    
	    long long int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    cout<<merge(a,n)<<endl;
	    
	}
	
	return 0;
}
