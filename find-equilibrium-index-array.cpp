// https://www.techiedelight.com/find-equilibrium-index-array/     <<--- optimised solution



#include<iostream>
using namespace std;
int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i = 0;i<t;i++){
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    int sum = 0;
	    for(int j=0;j<n;j++){
	        sum = sum + a[j];
	    }
	    int rightsum = 0;
	    int yes = 0;
	    int x;
	    for(int j=n-1;j>=0;j--){
	        if(rightsum == sum - (a[j] + rightsum)){
	            yes = 1;
	            x = j;
	            break;
	        }
	        rightsum = rightsum + a[j];
	    }
	    if(yes == 1){
	        cout<<x+1<<endl;
	    }else{
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}
