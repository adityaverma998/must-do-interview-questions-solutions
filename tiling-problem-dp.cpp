//    https://www.geeksforgeeks.org/tiling-problem/



#include<iostream>
using namespace std;

unsigned long long int tile(int n, unsigned long long int *a){
    
    if(a[n] != 0){
        return a[n];
    }
    if(n<1){
        return 0;
    }
    if(n == 1 || n == 2){
        return n;
    }
    
    a[n] = tile(n-1,a) + tile(n-2,a);
    
    return a[n];
}

int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    unsigned long long int a[n+1] = {0};
	    
	    cout<<tile(n,a)<<endl;
	    
	    
	}
	
	
	return 0;
}
