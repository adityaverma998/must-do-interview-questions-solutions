//          https://www.youtube.com/watch?v=99ssGWhLPUE
//        https://www.geeksforgeeks.org/maximum-sum-increasing-subsequence-dp-14/



#include<bits/stdc++.h>
using namespace std;

int misi(int a[], int n){
    int misi[n];
    for(int i=0;i<n;i++){
        misi[i] = a[i];
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j] < a[i] && misi[i] < misi[j] + a[i]){
                misi[i] = misi[j] + a[i];
            }
        }
    }
    
    int max = INT_MIN;
    
    for(int i=0;i<n;i++){
        if(max < misi[i]){
            max = misi[i];
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
        
        cout<<misi(a,n)<<endl;
    }

	
	return 0;
}
