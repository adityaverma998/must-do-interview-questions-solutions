/*


https://practice.geeksforgeeks.org/problems/find-the-odd-occurence/0

*/



#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	for(int i =0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    map <int , int > m;
	    
	    for(int j=0;j<n;j++){
	        if(m.find(a[j]) != m.end()){
	            auto x = m.find(a[j]);
	            ++(x->second);
	        }else{
	            m.insert(make_pair(a[j],1));
	        }
	    }
	    int xx = 0;
	    for(auto x = m.begin();x != m.end(); x++){
	        if((x)->second % 2 != 0){
	            xx = (x)->first;
	            break;
	        }
	    }
	    
	    cout<<xx<<endl;
	}
	
	return 0;
}
