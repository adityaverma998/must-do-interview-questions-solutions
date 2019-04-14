/*

https://www.geeksforgeeks.org/merging-intervals/


http://eclassesbyravindra.com/mod/page/view.php?id=6665


1. Sort the intervals based on increasing order of 
    starting time.
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack 
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top, 
       update stack top with the ending  time of current interval.
4. At the end stack contains the merged intervals. 



*/


#include<bits/stdc++.h>

using namespace std;

struct interval{
    int start;
    int end;
};

bool compare(struct interval a, struct interval b){
    return (a.start < b.start);
}

int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int n;
	    cin>>n;
	    
	    if(n<=0){
	        continue;
	    }
	    
	    struct interval a[n];
	    
	    for(int j=0;j<n;j++){
	        cin>>a[j].start;
	        cin>>a[j].end;
	    }
	    
	    sort(a,a+n,compare);
	    
	    stack < interval > s;
	    
	    s.push(a[0]);
	    
	    for(int j=1;j<n;j++){
	        if(s.top().end >= a[j].start){
	            //merge
	            s.top().end = (s.top().end >= a[j].end)?s.top().end:a[j].end;
	        }else{
	            // just push
	            s.push(a[j]);
	        }
	    }
	    
	    vector < interval > v;
	    while(!s.empty()){
	        v.push_back(s.top());
	        s.pop();
	    }
	    
	    reverse(v.begin(),v.end());
	    
	    for(auto it = v.begin(); it != v.end(); it++){
	        cout<<(*it).start<<" "<<(*it).end<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
