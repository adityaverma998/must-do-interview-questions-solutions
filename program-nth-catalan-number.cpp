//   https://www.geeksforgeeks.org/program-nth-catalan-number/
//   https://www.geeksforgeeks.org/advanced-c-boost-library/



#include<bits/stdc++.h>


#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision; 
using namespace std; 



int1024_t c[10000];

int1024_t cat(int n){
    if(c[n] == -1){
        if(n == 0 || n == 1){
            c[n] = 1;
        }else{
            int1024_t sum = 0;
            for(int i=0;i<n;i++){
                sum = sum + cat(i)*cat((n-1)-i);
            }
            c[n] = sum;
        }
    }
    return c[n];
}


int main()
{
	//code
        
    int t;
    cin>>t;
    
    for(int i=0;i<10000;i++){
        c[i] = -1;
    }
    
    for(int  i=0;i<t;i++){
        
        int n;
        cin>>n;
        
        cout<<cat(n)<<endl;
        
    }
        	
	return 0;
}
