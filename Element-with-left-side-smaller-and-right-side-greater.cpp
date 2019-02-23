/*

https://practice.geeksforgeeks.org/problems/unsorted-array/0
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
	    int x=0;
	    for(int j=1;j<n-1;j++){
	        int ele = a[j];
	        int elepresent = 1;
	        for(int k=0;k<j;k++){
	            if(ele < a[k]){
	                elepresent = 0;
	                break;
	            }   
	        }
	        if(elepresent == 1){
	            for(int k=j+1;k<n;k++){
	                if(ele > a[k]){
	                    elepresent = 0;
	                    break;
	                }
	            }
	            
	            if(elepresent == 1){
	                cout<<ele<<endl;
	                x=1;
	                break;
	            }
	            
	        }else{
	            continue;
	        }
	        
	    }
	    if(x==0){
	        cout<<"-1"<<endl;
	    }
	}
	
	return 0;
}
