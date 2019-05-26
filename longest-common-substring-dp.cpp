// watch tushar roy video on this then see gfg post        https://www.geeksforgeeks.org/longest-common-substring-dp-29/



#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n){
    int x[m+1][n+1];
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0){
                x[i][j] = 0;
            }else if(s1[i-1] == s2[j-1]){
                x[i][j] = x[i-1][j-1] + 1;
            }else{
                x[i][j] = 0;
            }
        }
    }
    
    int max = INT_MIN;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(max < x[i][j]){
                max = x[i][j];
            }
        }
    }
    
    return max;
}

int main()
{
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int m;
	    int n;
	    cin>>m>>n;
	    
	    string s;
	    string x;
	    cin>>s;
	    cin>>x;
	    
	    cout<<lcs(s,x,m,n)<<endl;
	    
	}
	
	return 0;
}
