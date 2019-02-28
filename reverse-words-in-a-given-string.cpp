/*

https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0
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
	    
	    string temp;
	    int len = s.length();
	    
	    stack <string> st;
	    
	    int no = 0;
	    
	    for(int j=0;j<=len-1;j++){
	        if(s[j] == '.' || j == len-1){
	            st.push(temp);
	            no = no + 1;
	            temp.erase();
	        }else{
	            temp.push_back(s[j]);
	            if(j == len-2){
	                temp.push_back(s[j+1]);
	            }
	        }
	    }
	   
	   while(!st.empty()){
	       
	       if(no == 1){
	           cout<<st.top();
	           st.pop();
	           break;
	       }
	       
	       cout<<st.top()<<".";
	       st.pop();
	       no--;
	   }
	   
	   cout<<endl;
	}
	
	
	return 0;
}
