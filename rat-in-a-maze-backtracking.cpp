//      https://www.youtube.com/watch?v=MNQrDlaHAbw&t=3445s



{
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */
vector <string> v;

void findpath(int m[MAX][MAX], int n, int x, int y, int p[MAX][MAX], string s){
    if(x<0 || y<0 || x >= n || y>=n){
        return ;
    }
    if(m[x][y] == 0 || p[x][y] == 1){
        return;
    }
    if(x == n-1 && y == n-1){
        v.push_back(s);
        return;
    }
    p[x][y] = 1;
    
    findpath(m,n,x-1,y,p,s+"U");
    findpath(m,n,x+1,y,p,s+"D");
    findpath(m,n,x,y-1,p,s+"L");
    findpath(m,n,x,y+1,p,s+"R");
    
    p[x][y] = 0;
    
}


vector<string> printPath(int m[MAX][MAX], int n)
{
    //Your code here
    
    int pa[MAX][MAX];
    
    memset(pa,0,sizeof(pa));
    
    findpath(m,n,0,0,pa,"");
    
    vector <string> x = v;
    
    v.clear();
    
    sort(x.begin(),x.end());
    
    return x;
    
    
}
