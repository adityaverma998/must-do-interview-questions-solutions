//   https://practice.geeksforgeeks.org/problems/sorted-matrix/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    priority_queue <int , vector <int> , greater <int> > q;
	    
	    for(int j=0;j<(n*n);j++){
	        int x;
	        cin>>x;
	        q.push(x);
	    }
	    
	    for(int j=0;j<(n*n);j++){
	        cout<<q.top()<<" ";
	        q.pop();
	    }
	    
	    cout<<endl;
	}
	
	
	
	return 0;
}
