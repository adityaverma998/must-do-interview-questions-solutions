/*
https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/

*/


#include <bits/stdc++.h>

using namespace std;

int sum(int a[], int n){
    
    for(int i=0;i<n;i++){
        a[i] = a[i] * a[i];
    }
    
    sort(a,a+n);
    
    for(int i = n-1; i >= 2;i--){
        int l = 0;
        int r = i-1;
        
        while(l<r){
            if(a[l] + a[r] == a[i]){
                return 1;
            }
            
            (a[l]+a[r] < a[i]) ? l++ : r--;
        }
    }
    
    return 0;
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
        
        int decision = sum(a,n);
        if(decision == 1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
    return 0;
}
