//    https://www.geeksforgeeks.org/print-all-subarrays-with-0-sum/



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
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    int sum = 0;
	    int c = 0;
	    
	    unordered_multimap <int , int> m;
	    
	    m.insert(make_pair(0,1));
	    
	    for(int j=0;j<n;j++){
	        
	        sum = sum + a[j];
	        
	        if(m.find(sum) != m.end()){
	            auto it = m.find(sum);
	            while(it != m.end() && it->first == sum){
	                ++c;
	                ++it;
	            }
	        }
	        
	        m.insert(make_pair(sum,1));
	    }

	    cout<<c<<endl;
	    
	}
	
	return 0;
}
