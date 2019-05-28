#include<bits/stdc++.h>
#define x 400
#define lli long long int
using namespace std;

lli count(lli a[], lli n, lli k,long long int dp[x][x]){
    
    
//if sum is zero then we can form it using only one way i.e. using no coins
    if(k == 0){
         return 1;
    }
//if sum is less than zero than no way to form the sum
    if(k < 0){
        return 0;
    }

    if(n<=0){//
        return 0;
    }
    
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    
    dp[n][k] = count(a,n-1,k,dp) + count(a,n,k-a[n-1],dp);
    
    return dp[n][k];
}

int main()
{
	
	lli t;
	cin>>t;
	
	for(lli i=0;i<t;i++){
	    lli n;
	    cin>>n;
	    long long int dp[x][x];
	    memset(dp,-1,sizeof(dp));
	    lli a[n];
	    for(lli j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    lli k;
	    cin>>k;
	    cout<<count(a,n,k,dp)<<endl;
	}
	
	return 0;
}
