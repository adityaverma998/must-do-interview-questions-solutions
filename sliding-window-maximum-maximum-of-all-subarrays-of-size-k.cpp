// IMP question

// https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/


// rbr video link -   http://eclassesbyravindra.com/mod/page/view.php?id=6884


#include<bits/stdc++.h>
using namespace std;

void print(int a[], int n, int k){
    deque <int> dq(k);
    int i;
    for(i=0;i<k;++i){
        while(!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i<n;++i){
        cout<<a[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && a[i] >= a[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<a[dq.front()];
}

int main()
{
	//code
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;
	    int k;
	    cin>>n;
	    cin>>k;
	    int a[n];
	    for(int j=0;j<n;j++){
	        cin>>a[j];
	    }
	    print(a,n,k);
	    cout<<endl;
	}
	return 0;
}
