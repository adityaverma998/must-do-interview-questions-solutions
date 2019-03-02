/*

https://practice.geeksforgeeks.org/problems/anagram/0

*/





#include<bits/stdc++.h>

using namespace std;

int main()
{
	//code
	
	ios_base::sync_with_stdio(false); // used to increase std input output time 
    cin.tie(NULL);                  //
	
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    unordered_map <char , int> m; // unordered map is better than map - see - https://thispointer.com/map-vs-unordered_map-when-to-choose-one-over-another/	    
	    string s;
	    string p;
	    
	    cin>>s;
	    cin>>p;
	    
	    if(s.length() != p.length()){
	        cout<<"NO"<<endl;
	        continue;
	    }
	    
	    for(int j=0;j<s.length();j++){
	        if(m.find(s[j]) != m.end()){
	            auto x = m.find(s[j]);
	            (x->second)++; 
	        }else{
	            m.insert(make_pair(s[j],1));
	        }
	    }
	    
	    for(int j=0;j<p.length();j++){
	        m.erase(p[j]);
	    }
	    
	    int x = 0;
	    for(auto i = m.begin(); i != m.end(); i++){
	        x++;
	        break;
	    }
	    
	    if(x == 0){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
	

	return 0;
}
