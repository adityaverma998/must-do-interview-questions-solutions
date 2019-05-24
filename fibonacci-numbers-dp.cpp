//   https://www.geeksforgeeks.org/overlapping-subproblems-property-in-dynamic-programming-dp-1/



#include<bits/stdc++.h>
using namespace std;

long long int a[10000] ;

long long int fib(long long int n){
    if(a[n] == -1){
        if(n==1 || n==0){
            a[n] = n;
        }else{
            a[n] = (fib(n-1) + fib(n-2)) %1000000007;
        }
    }
    return a[n];
}

int main()
{
	//code
	
	long long int t;
	cin>>t;
	
	for(long long int i=0;i<10000;i++){
	    a[i] = -1;
	}
	
	for(long long int i=0;i<t;i++){
	    
	    long long int n;
	    cin>>n;
	    
	    cout<<(fib(n))<<endl;

	}
	
	return 0;
}
