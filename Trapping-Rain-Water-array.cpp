//    https://www.geeksforgeeks.org/trapping-rain-water/

#include <bits/stdc++.h>

using namespace std;

int water(int a[], int n){
    int left[n];
    int right[n];
    left[0] = a[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],a[i]);
    }
    right[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--){
        right[i] = max(right[i+1],a[i]);
    }
    int w = 0;
    for(int i=0;i<n;i++){
        w += min(left[i],right[i]) - a[i];
    }
    return w;
}

int main(){
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        
        int n;
        cin>>n;
        
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        
        cout<<water(a,n)<<endl;
    }
    
    return 0;
}
