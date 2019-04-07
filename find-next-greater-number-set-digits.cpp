//   https://www.geeksforgeeks.org/find-next-greater-number-set-digits/


//  http://eclassesbyravindra.com/mod/page/view.php?id=4630


#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

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
	    
	    int index;
	    for(int j = n-1; j >=0 ; j--){
	        if(a[j-1] < a[j]){
	            index = j-1;
	            break;
	        }
	    }
	    
	    int min = INT_MAX;
	    int minindex;
	    int y = 0;
	    
	    for(int j = index+1; j<n;j++){
	          if(a[j] < min && a[j] > a[index]){
	              min = a[j];
	              y = 1;
	              minindex = j;
	          }
	    }
	    
	    
	    
	    swap(&a[index],&a[minindex]);
	    
	    sort(a+index+1,a+n);
	    
	    for(int j=0;j<n;j++){
	        cout<<a[j]<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
