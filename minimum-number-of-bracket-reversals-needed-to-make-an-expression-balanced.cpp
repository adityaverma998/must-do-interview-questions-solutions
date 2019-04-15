/*

https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/


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
	    
	    
	    if(s.size() % 2 != 0){
	        cout<<"-1"<<endl;
	        continue;
	    }
	    
	    stack <char> st;
	    
	    for(int j=0;j<s.size();j++){
	        char c = s[j];
	        if(st.empty()){
	            st.push(c);
	            continue;
	        }
	        if(st.top() == '{' && c == '}'){
	            st.pop();
	            continue;
	        }
	        st.push(c);
	    }
	    
	    int red_len = st.size();
	    int n=0;
	    while(!st.empty() && st.top() == '{'){
	        st.pop();
	        n++;
	    }
	    
	    cout<<(red_len/2 + n%2)<<endl;
	    
	    /*
	   DONT USE THIS CONCEPT --- GIVEN IN ALGO-- USE ABOVE IMPLEMENTATION 
	    
	    int closing = 0;
	    int opening = 0;
	    
	    while(!st.empty()){
	        if(st.top() == '{'){
	            opening++;
	            st.pop();
	        }else{
	            closing++;
	            st.pop();
	        }
	    }
	    
	    
	    
	    cout<<(ceil(opening/2) + ceil(closing/2))<<endl;
	    */
	}
	
	return 0;
}
