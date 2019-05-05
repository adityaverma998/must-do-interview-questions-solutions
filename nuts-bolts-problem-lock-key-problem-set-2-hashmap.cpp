//    https://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem-set-2-hashmap/


//   https://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem/


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
	    
	    char s1[n];
	    char s2[n];
	    
	    for(int j=0;j<n;j++){
	        cin>>s1[j];
	    }
	    for(int j=0;j<n;j++){
	        cin>>s2[j];
	    }
	    
	    unordered_map < char , int > m;
	    for(int j=0;j<n;j++){
	        m[s1[j]] = j;
	    }
	    for(int j=0;j<n;j++){
	        if(m.find(s2[j]) != m.end()){
	            s1[j] = s2[j];
	        }
	    }
	    
	    sort(s1,s1+n);
	    sort(s2,s2+n);
	    
	    for(int j=0;j<n;j++){
	        cout<<s1[j]<<" ";
	    }
	    cout<<endl;
	    for(int j=0;j<n;j++){
	        cout<<s2[j]<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
