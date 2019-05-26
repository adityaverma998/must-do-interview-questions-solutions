/*

http://eclassesbyravindra.com/mod/page/view.php?id=4021

*/





#include<bits/stdc++.h>
using namespace std;

int count(int p[], int n){

        p[0] = 0;
        p[1] = 2;
        p[2] = 3;
        
    
    for(int i = 3; i<=n;i++){
        p[i] = (p[i-1] + p[i-2])%1000000007;
    }
    
    return p[n];
}

int main()
{
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    
	    int p[n+1];
	    memset(p,0,sizeof(p));
	    cout<<count(p,n)<<endl;
	}
	
	return 0;
}
