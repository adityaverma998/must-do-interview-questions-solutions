

#include<bits/stdc++.h>
#define lli long long int
#define size 200
using namespace std;


int lcs(string x, string y, int m, int n, lli a[size][size]){
    //base cases
    
    if(m == 0 || n == 0){
        return 0;
    }
    
    //------
    
    if(a[m][n] != -1){
        return a[m][n];
    }
    
    if(x[m-1] == y[n-1]){
        a[m][n] = 1 + lcs(x,y,m-1,n-1,a);
    }else{
        a[m][n] = max(lcs(x,y,m-1,n,a),lcs(x,y,m,n-1,a));
    }
    
    return a[m][n];
    
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int m,n;
	    cin>>m;
	    cin>>n;
	    
	    lli a[size][size];
	    memset(a,-1,sizeof(a));
	    
	    string x,y;
	    cin>>x;
	    cin>>y;
	    
	    cout<<lcs(x,y,m,n,a)<<endl;
	}
	
	return 0;
}
