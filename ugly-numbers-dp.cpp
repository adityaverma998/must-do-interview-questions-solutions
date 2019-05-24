//       https://www.geeksforgeeks.org/ugly-numbers/




#include<bits/stdc++.h>
using namespace std;

long long int ugly[10000];

long long int uglyno(int n){
    long long int i2 = 0;
    long long int i3 = 0;
    long long int i5 = 0;
    
    
    
    long long int next_multiple_2 = 2;
    long long int next_multiple_3 = 3;
    long long int next_multiple_5 = 5;
    long long int next_no = 1;
    ugly[0] = 1;
    
    for(long long int i = 1;i<n;i++){
        next_no = min(next_multiple_2,min(next_multiple_3,next_multiple_5));
        
        ugly[i] = next_no;
        
        if(next_no == next_multiple_2){
            i2 = i2+1;
            next_multiple_2 = ugly[i2] * 2;
        }
        if(next_no == next_multiple_3){
            i3 = i3+1;
            next_multiple_3 = ugly[i3] * 3;
        }
        if(next_no == next_multiple_5){
            i5 = i5+1;
            next_multiple_5 = ugly[i5] * 5;
        }
        
    }
    
    return next_no;
}


int main()
{
	//code

    long long int t;
    cin>>t;
    
    uglyno(10000);
    
    for(long long int i=0;i<t;i++){
        
        long long int n;
        cin>>n;
        
        cout<<ugly[n-1]<<endl;
        
        
    }
	
	return 0;
}
