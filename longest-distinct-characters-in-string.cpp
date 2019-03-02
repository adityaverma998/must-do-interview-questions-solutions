/*

https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string/0

*/



#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    string s;
	    cin>>s;
	    int n = s.length();
	    int k = 0;
	    int l = 0;
	    int max = 0;
	    int realmax = 0;
	    
	    map <char , int> m;
	    
	    for(;k<n  && l<n;){
	        if(m.find(s[l]) != m.end()){
	            k++;
	            l=k;
	            l++;
	            if(realmax < max){
	                realmax = max;
	            }
	            max = 1;
	            m.clear();
	            m.insert(make_pair(s[k],1));
	            
	        }else if(m.find(s[l]) == m.end()){
	            m.insert(make_pair(s[l],1));
	            l++;
	            max = max + 1;
	        }
	    }
	    if(realmax < max){
	        realmax = max;
	    }
	    cout<<realmax<<endl;
	}
	
	return 0;
}
