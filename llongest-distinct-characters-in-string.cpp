//    


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
	    
	    int count = 0;
	    int gmax = 0;
	    unordered_map <char,int> m;
	    
	    for(int i=0;i<s.length();i++){
	        
	        if(m.find(s[i]) != m.end()){
	            i = m.find(s[i])->second + 1;
	            m.clear();
	            
	            m.insert(make_pair(s[i],i));
	            count = 1;
	        }else{
	            m.insert(make_pair(s[i],i));
	            ++count;
	        }
	        
	        if(gmax<count){
	            gmax = count;
	        }
	        
	    }
	    
	    cout<<gmax<<endl;
	    m.clear();
	    
	}
	
	return 0;
}
