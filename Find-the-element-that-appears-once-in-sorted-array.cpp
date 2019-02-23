/*


https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array/0

*/


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
	    int ele;int count=0;
	    for(int j=0;j<n;){
	        ele = a[j];
	        if(ele == a[j+1]){
	            for(int k=j+2;k<n;k++){
	                if(ele != a[k]){
	                    j = k;
	                    break;
	                }
	            }
	        }else{
	            cout<<ele<<endl;
	            break;
	        }
	    }
	    
	}
	
	return 0;
}
