/*

https://www.youtube.com/watch?v=_Lf1looyJMU

https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/

*/


#include<bits/stdc++.h>
using namespace std;
#define x 100

int min(int a, int b){
    if(a<b){
        return a;
    }
    return b;
}

int maxsq(int m, int n, bool a[x][x]){
    int sol[m][n];
    for(int i=0;i<m;i++){
        sol[i][0] = a[i][0];
    }
    for(int j=0;j<n;j++){
        sol[0][j] = a[0][j];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(a[i][j] == 1){
                sol[i][j] = min(sol[i][j-1],min(sol[i-1][j],sol[i-1][j-1])) + 1;
            }else{
                sol[i][j] = 0;
            }
        }
    }
    int max = INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            
            if(max < sol[i][j]){
                max = sol[i][j];
            }
        }
    }
    
    return max;
}


int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int m;
	    int n;
	    cin>>m>>n;
	    
	    bool a[x][x];
	    for(int j=0;j<m;j++){
	        for(int k=0;k<n;k++){
	            cin>>a[j][k];
	        }
	    }
	    
	    cout<<maxsq(m,n,a)<<endl;
	    
	}
	
	
	return 0;
}


