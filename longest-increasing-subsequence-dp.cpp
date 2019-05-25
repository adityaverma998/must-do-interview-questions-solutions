//          https://www.youtube.com/watch?v=CE2b_-XfVDk

//         https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/

#include<bits/stdc++.h>
using namespace std;

int lis(int a[], int n){
    int lis[n];
    for(int i=0;i<n;i++){
        lis[i] = 1;
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i] && lis[i] < lis[j]+1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(max < lis[i]){
            max = lis[i];
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
        
        int n;
        cin>>n;
        
        int a[n];
        
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        
        cout<<lis(a,n)<<endl;

    }

	
	return 0;
}

