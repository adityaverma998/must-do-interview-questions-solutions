//      https://www.geeksforgeeks.org/print-concatenation-of-zig-zag-string-form-in-n-rows/


#include<iostream>
#include <string>
#define TRUE 1
#define FALSE 0

using namespace std;

void print(string s, int n){
    if(n == 1){
        cout<<s;
        return;
    }
    string  a[n];
    int row = 0;
    bool down = TRUE;
    for(int i=0;i<s.length();i++){
        a[row].push_back(s[i]);
        if(row == n-1){
            down = FALSE;
        }
        if(row == 0){
            down = TRUE;
        }
        down ? (++row) : (--row) ;
    }
    
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}

int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    string s;
	    cin>>s;
	    int n;
	    cin>>n;
	    
	    print(s,n);
	    
	    cout<<endl;
	}
	
	return 0;
}
