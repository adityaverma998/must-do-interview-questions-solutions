// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0


#include <iostream>
using namespace std;

int max(int a, int b){
    if(a>=b){
        return a;
    }else{
        return b;
    }
}

int kadane(int a[], int n){
    int currentmax = a[0];
    int globalmax = a[0];
    for(int i=1;i<n;i++){
        currentmax = max(a[i], currentmax + a[i]);
        if(currentmax > globalmax){
            globalmax = currentmax;
        }
        if(currentmax < 0){
            currentmax = 0;
        }
    }
    return globalmax;
}

int main() {
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
	    int sum = kadane(a,n);
	    cout<<sum<<endl;
	}
	
	return 0;
}
