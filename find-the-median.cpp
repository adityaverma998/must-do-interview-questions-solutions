//     https://practice.geeksforgeeks.org/problems/find-the-median/0



#include<iostream>
#include <algorithm>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    vector <int> v;
	    for(int j=0;j<n;j++){
	        int x;
	        cin>>x;
	        v.push_back(x);
	    }
	    
	    sort(v.begin(),v.end());
	    
	    int no=0;
	    for(auto it = v.begin(); it != v.end(); it++){
	        no++;
	    }
	    
	    if(v.size() % 2 == 0){
	        cout<<(v[(no/2) - 1] + v[(no/2)])/2<<endl;
	    }else{
	        cout<<v[no/2]<<endl;
	    }
	    
	}
	
	return 0;
}
