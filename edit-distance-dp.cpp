/*

https://www.geeksforgeeks.org/edit-distance-dp-5/

watch all edit distance videos -    http://eclassesbyravindra.com/mod/page/view.php?id=3992
  

*/



#include<iostream>
using namespace std;

int dist(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i == 0){
                dp[i][j] = j;
                continue;
            }
            if(j == 0){
                dp[i][j] = i;
                continue;
            }
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
        }
    }
    
    return dp[m][n];
}

int main()
{
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int m;
	    int n;
	    cin>>m>>n;
	    
	    string s1;
	    string s2;
	    cin>>s1>>s2;
	    
	    cout<<dist(s1,s2,m,n)<<endl;
	    
	}
	
	return 0;
}
