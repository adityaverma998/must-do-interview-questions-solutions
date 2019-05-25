/*


https://www.geeksforgeeks.org/longest-consecutive-subsequence/
http://eclassesbyravindra.com/mod/page/view.php?id=3980


https://www.youtube.com/watch?v=VeJOswJTDos

*/







#include<bits/stdc++.h>
using namespace std;

int lcs(int a[], int n){
    unordered_map <int,int> m;
    int ans = 0;
    for(int i=0;i<n;i++){
        m.insert(make_pair(a[i],0));
    }
    
    for(int i=0;i<n;i++){
        if(m.find(a[i] - 1) == m.end()){
            int j = a[i];
            while(m.find(j) != m.end()){
                ++j;
            }
            ans = max(ans,j - a[i]);
        }
        
    }
    
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
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    cout<<lcs(a,n)<<endl;
	    
	}
	
	return 0;
}
