/*

https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/


http://eclassesbyravindra.com/mod/page/view.php?id=3319

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
	    
	    stack <char> st;
	    
	    for(int j=0;j<s.size();j++){
	        char c = s[j];
	        
	        if(st.empty() && (c == ']' || c == '}' || c == ')')){
	            st.push(c);
	            continue;
	        }
	        
	        if(c == '[' || c == '(' || c == '{'){
	            st.push(c);
	            continue;
	        }
	        
	        if( c == ']' || c == '}' || c == ')'  ){
	            if(st.top() == '[' && c ==']'){
	                st.pop();
	                continue;
	            }
	            if(st.top() == '{' && c == '}'){
	                st.pop();
	                continue;
	            }
	            if(st.top() == '(' && c == ')'){
	                st.pop();
	                continue;
	            }
	            st.push(c);
	            continue;
	        }
	        
	        
	    }
	    
	    if(st.empty()){
	        cout<<"balanced"<<endl;
	    }else{
	        cout<<"not balanced"<<endl;
	    }
	    
	}
	return 0;
}
