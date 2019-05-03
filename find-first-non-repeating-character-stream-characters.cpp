//    https://ideone.com/fK0kyG

//    https://www.geeksforgeeks.org/find-first-non-repeating-character-stream-characters/



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
	    char a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    unordered_map <char,int> m;
	    list <char> l;
	    for(int j=0;j<n;j++){
	        if(l.empty()){
	            l.push_back(a[j]);
	        }else if(m.find(a[j]) == m.end()){
	            l.push_back(a[j]);
	        }
	        
	        m[a[j]]++;
	        
	        while(!l.empty() && m[l.front()] != 1){
	            l.pop_front();
	        }
	        if(l.empty()){
	            cout<<"-1 ";
	        }else{
	            cout<<l.front()<<" ";
	        }
	    }
	    cout<<endl;
	}
	
	return 0;
}
