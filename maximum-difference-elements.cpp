/*

http://www.crazyforcode.com/maximum-difference-elements/

*/




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
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    //------------logic
	    int min_element=a[0];
        int diff=a[1]-a[0];
        
        for(int j=1;j<n;j++)
        {
            if(a[j]-min_element>diff){
                diff=a[j]-min_element;
            }    
            if(a[j]<min_element){
                min_element=a[j];
            }
        }
        //-----------------
	    cout<<(diff)<<endl;
	}
	
	return 0;
}
