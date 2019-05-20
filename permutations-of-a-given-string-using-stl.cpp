//     https://www.geeksforgeeks.org/permutations-of-a-given-string-using-stl/


#include<bits/stdc++.h>
using namespace std;

void prem(string s){
    
    sort(s.begin(),s.end());
    
    do{
        cout<<s<<" ";
    }while(next_permutation(s.begin(),s.end()));
}

int main()
{
	//code
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    string s;
	    cin>>s;
	    
	    prem(s);
	    cout<<endl;
	}
	
	return 0;
}
