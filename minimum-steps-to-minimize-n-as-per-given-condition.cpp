//             https://practice.geeksforgeeks.org/problems/minimum-steps-to-minimize-n-as-per-given-condition/0


#include<bits/stdc++.h>
using namespace std;

int a[100000] = {0};

int p(int n){
    
    if(n <= 1){
        return 0;
    }
    if(a[n] > 0){
        return a[n];
    }
    
    int ans = 1 + p(n-1);
    
    
    if(n%2 == 0){
        ans = min(ans, 1 + p(n/2));
    }
    if(n%3 == 0){
        ans = min(ans, 1 + p(n/3));
    }
    a[n] = ans;
    
    return ans;
}


int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    
	    for(int j=0;j<=n;j++){
	        a[j] = 0;
	    }
	    
	    cout<<p(n)<<endl;
	    
	    
	}
	
	
	return 0;
}
