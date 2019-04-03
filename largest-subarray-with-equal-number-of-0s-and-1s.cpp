// good question

// http://eclassesbyravindra.com/mod/page/view.php?id=3702


// http://eclassesbyravindra.com/mod/page/view.php?id=5379





{
#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int n);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<maxLen(a,n)<<endl;
		
	}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
//Your code here

    int s[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }
    }
    
    for(int i=0;i<n;i++){
        s[i] = arr[i] + sum;
        sum = s[i];
    }
    
    
    map <int , int> m;
    int maxsize = INT_MIN;
    
    //condition 1 : if same no repeats in sum array
    
    for(int i=0;i<n;i++){
        if(m.find(s[i]) != m.end()){
            auto x = m.find(s[i]);
            int index = x->second;
            int ii = i - index;
            if(maxsize < ii){
                maxsize = ii;
            }
        }else{
            m.insert(make_pair(s[i],i));
        }
    }
    
    //condition 2 : if 0 occurs in sum array
    
    for(int i=0;i<n;i++){
        if(s[i] == 0){
            if(maxsize < i+1){
                maxsize = i+1;
            }
        }
    }
    
    //condition 3 : if maxsize does not change
    
    if(maxsize == INT_MIN){
        maxsize = 0;
    }
    
    return maxsize;

}
