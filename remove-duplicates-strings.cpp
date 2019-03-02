/*

https://practice.geeksforgeeks.org/problems/remove-duplicates/0
*/


#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	
	
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    char s[1000];
	    scanf(" %[^\n]s",s);  //  <<<<<----- ***********THIS READS BOTH STRINGS WITH AND WITHOUT SPACES - WHEREAS CIN READS WITHOUT SPACES AND GETLINE READS WITH SPACES*******
	    
	    int n = strlen(s);
	    
	    map <char , int> m;
	    
	    for(int j = 0; j < n; j++){
	        if(m.find(s[j]) != m.end()){
	            //ha
	        }else{
	            // nae ha
	            cout<<s[j];
	            m.insert(make_pair(s[j],1));
	        }
	    }
	    
	    cout<<endl;
	}
	
	
	return 0;
}
