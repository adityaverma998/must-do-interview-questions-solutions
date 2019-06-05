// read this ->>>  https://algorithms.tutorialhorizon.com/dynamic-programming-coin-in-a-line-game-problem/

#include<bits/stdc++.h>
using namespace std;
int dp[200][200];
int maxprofit(int a[], int s, int n){
    if(s == n){
        return a[s];
    }
    if(s+1 == n){
        return max(a[s],a[n]);
    }
    if(dp[s][n] != -1){
        return dp[s][n];
    }
    dp[s][n] = max(a[s] + min(maxprofit(a,s+2,n),maxprofit(a,s+1,n-1)), a[n] + min(maxprofit(a,s+1,n-1),maxprofit(a,s,n-2)));
    return dp[s][n];
    
}

int main()
{
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    memset(dp,-1,sizeof(dp));
	    cout<<maxprofit(a,0,n-1)<<endl;
	}
	
	return 0;
}
