//   https://practice.geeksforgeeks.org/problems/equilibrium-point/0


#include <iostream>

using namespace std;

int equi(int a[], int sum, int n){
    int s = 0;
    if(n == 1){
        return 1;
    }
    for(int i=1;i<n;i++){
        s = s + a[i-1];
        if(s == (sum - s - a[i])){
            return i+1;
        }
    }
    return -1;
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
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += a[j];
        }
        int pos = equi(a,sum,n);
        cout<<pos<<endl;
    }
    return 0;
}
