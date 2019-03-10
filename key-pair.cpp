/*rbr*/



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
	    int a[n];
	    int sum;
	    cin>>sum;
	    
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    multimap <int,int> m;
	    int value = 1;
	    for(int j=0;j<n;j++){
	        m.insert(make_pair(a[j],value++));
	    }
	    int x = 0;
	    for(int j=0;j<n;j++){
	        int no1 = a[j];
	        int no2 = sum - a[j];
	        auto y = m.find(no1);
	        m.erase(y);
	        
	        if(m.find(no2) != m.end()){
	                x = 1;
	                break;
	        }
	        
	        m.insert(make_pair(no1,1));
	    }
	    if(x == 0){
	        cout<<"No"<<endl;
	    }else{
	        cout<<"Yes"<<endl;
	    }
	}
	
	return 0;
}
