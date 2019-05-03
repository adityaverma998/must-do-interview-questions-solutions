//   https://www.geeksforgeeks.org/minimum-number-of-palindromic-subsequences-to-be-removed-to-empty-a-binary-string/


#include<iostream>
using namespace std;

int isp(char a[], int s, int e){
    if(s <= e){
        int y = 0;
        while(s<=e){
            if(a[s] != a[e]){
                y = 1;break;
            }
            s++;
            e--;
        }
        if(y==1){
            return 0;
        }else{
            return 1;
        }
    }
}

int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    char a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    
	    if(isp(a,0,n-1)){
	        cout<<"1\n";
	    }else{
	        cout<<"2\n";
	    }
	    
	}
	
	
	return 0;
}
