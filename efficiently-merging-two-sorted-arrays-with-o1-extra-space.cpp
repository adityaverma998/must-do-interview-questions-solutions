//        https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays/0/?track=md-arrays&batchId=144


#include<bits/stdc++.h>
using namespace std;

int main()
{
	//code

    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int m,n;
        cin>>m>>n;
        
        int a[m];
        int b[n];
        
        for(int j=0;j<m;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        
        int l=0;
        int r=0;
        
        while(l<m && r<n){
            if(a[l]<b[r]){
                cout<<a[l++]<<" ";
            }else if(a[l]>b[r]){
                cout<<b[r++]<<" ";
            }else{
                cout<<a[l++]<<" ";
                cout<<b[r++]<<" ";
            }
        }
        
        while(l<m){
            cout<<a[l++]<<" ";
        }
        while(r<n){
            cout<<b[r++]<<" ";
        }
        
        cout<<endl;
    }
    	
	return 0;
}
