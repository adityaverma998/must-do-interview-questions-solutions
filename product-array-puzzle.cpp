//  http://eclassesbyravindra.com/mod/page/view.php?id=3528


#include<iostream>
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
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    int leftpro[n];
	    int rightpro[n];
	    
	    int pro = 1;
	    for(int j=0;j<n;j++){
	        leftpro[j] = pro * a[j];
	        pro = leftpro[j];
	    }
	    
	    int pr = 1;
	    for(int j=n-1;j>=0;j--){
	        rightpro[j] = a[j] * pr;
	        pr = rightpro[j];
	    }
	    int p;
	    for(int j=0;j<n;j++){
	        p = 1;
	        if(j-1 >= 0){
	            p = leftpro[j-1] * p;
	        }
	        if(j+1 < n){
	            p = rightpro[j+1] * p;
	        }
	        cout<<p<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
