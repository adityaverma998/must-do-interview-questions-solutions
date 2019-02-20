//   https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

#include <iostream>
#include <stack>
using namespace std;

int main() {
	//code
	
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    stack <int> s;
	    int max = -1000;
	    for(int i=n-1;i>=0;i--){
	        if(max <= a[i]){
	            max = a[i];
	            s.push(max);
	        }
	    }
	    while(!s.empty()){
	        cout<<s.top()<<" ";
	        s.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
