/*

https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0
*/



#include<bits/stdc++.h>
using namespace std;

int rotateleft(string s, int n, string x){
    string p = s;
    for(int i=0;i<=n-2;i++){
        p[i] = s[i+2];
    }
    int i=0;
    for(int k=n-1;k<=n;k++){
        p[k] = s[i++];
    }
    i=0;
    if(p == x){
        return 1;
    }else{
        return 0;
    }
}

int rotateright(string s, int n, string x){
    string p = s;
    for(int i = 0; i<=n-2;i++){
        p[i+2] = s[i];
    }
    int i = 0;
    for(int k = n-1;k<=n;k++){
        p[i++] = s[k];
    }
    i=0;
    if(p == x){
        return 1;
    }else{
        return 0;
    }
}

int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    string s;
	    cin>>s;
	    
	    string x;
	    cin>>x;
	    
	    int n = s.length();
	    if(x.length() != s.length()){
	        continue;
	    }
	    if(rotateleft(s,n-1,x)){
	        cout<<"1"<<endl;
	    }else if(rotateright(s,n-1,x)){
	        cout<<"1"<<endl;
	    }else{
	        cout<<"0"<<endl;
	    }
	    
	    
	}
	
	return 0;
}
