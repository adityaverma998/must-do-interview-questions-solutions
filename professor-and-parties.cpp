//   https://practice.geeksforgeeks.org/problems/professor-and-parties/0

// used unoredered_map instead of using map 


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
	    
	    unordered_map <int , int> m;
	    
	    for(int j=0;j<n;j++){
	        if(m.find(a[j]) != m.end()){
	            ++(m.find(a[j])->second) ;
	        }else{
	            m.insert(make_pair(a[j],1));
	        }
	    }
	    int x = 0;
	    for(int j=0;j<n;j++){
	        if(m.find(a[j])->second > 1){
	            x = 1;
	            break;
	        }
	    }
	    
	    if(x == 0){
	        cout<<"GIRLS"<<endl;
	    }else{
	        cout<<"BOYS"<<endl;
	    }
	    
	}
	
	
	return 0;
}
