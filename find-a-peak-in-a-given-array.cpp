//     https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/


{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return the index of any
   peak element present in the array */
// arr: input array
// n: size of array

int findpeak(int arr[], int s, int e, int n){
        
        
        int mid = (s+e)/2;
        if((mid==0 || arr[mid-1]<=arr[mid])&&(mid==n-1 || arr[mid+1]<=arr[mid])){
            return mid;
        }else if(mid>0 && arr[mid-1]>arr[mid]){
            return findpeak(arr,s,(mid-1),n);
        }else{
            return findpeak(arr,(mid+1),e,n);
        }
        
    
    
}

int peakElement(int arr[], int n)
{
   // Your code here
   
   return findpeak(arr,0,n-1,n);
   
   
      
   
}
