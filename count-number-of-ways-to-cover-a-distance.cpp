//     https://www.geeksforgeeks.org/count-number-of-ways-to-cover-a-distance/

#include<bits/stdc++.h>
#define x 100
using namespace std;

int total(int n, int b[x]){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return 1;
    }
    if(b[n] != -1){
        return b[n];
    }
    b[n] = (total(n-1,b) + total(n-2,b) + total(n-3,b));
    return b[n];
}


int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    
	        int n;
	        cin>>n;
	        int b[x];
	        memset(b,-1,sizeof(b));
	        cout<<total(n,b)<<endl;
	    
	}
	
	return 0;
}
