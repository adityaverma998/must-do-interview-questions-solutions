#include<iostream>
using namespace std;
int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    
	    int a[n-1];
	    for(int j=0;j<n-1;j++){
	        cin>>a[j];
	    }
	    
	    int sum = 0;
	    
	    int Asum = (n*(n+1))/2;
	    
	    for(int j=0;j<n-1;j++){
	        sum = sum + a[j];
	    }
	    
	    cout<<(Asum-sum)<<endl;
	    
	    
	}
	
	return 0;
}
