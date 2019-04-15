/*

https://www.geeksforgeeks.org/the-stock-span-problem/


http://eclassesbyravindra.com/mod/page/view.php?id=3321

NOTE : in line no 42, if we interchange the conditions then we will get segmentation fault.
*/



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
	    
	    if(n<=0){
	        continue;
	    }
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    stack <int> s;
	    int st[n];
	    s.push(0);
	    st[0] = 1;
	    
	    for(int j=1;j<n;j++){
	        
	        while(( (!s.empty()) && a[s.top()] <= a[j])  ){
	            s.pop();
	        }
	        
	        if(s.empty()){
	            st[j] = (j+1);
	        }else{
	            st[j] = (int)(j - s.top());
	        }
	        
	        s.push(j);
	        
	    }
	    
	    for(int j=0;j<n;j++){
	        cout<<st[j]<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
