/*
dont go for gfg here, watch rbr video -  
http://eclassesbyravindra.com/mod/page/view.php?id=3514   
&  
http://eclassesbyravindra.com/mod/page/view.php?id=6696
*/

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int n;
    priority_queue <int> q1;
    priority_queue <int, vector<int>, greater<int> > q2;
    cin>>n;
    int cur_median;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        
        if(i==0){
            q1.push(x);
            cur_median = x;
            cout<<floor(cur_median)<<endl;
            continue;
        }
        
        if(q1.size() > q2.size()){
            if(x < cur_median){
                int ele = q1.top();
                q1.pop();
                q2.push(ele);
                q1.push(x);
                cur_median = ( q1.top() + q2.top() ) / 2;
                cout<<floor(cur_median)<<endl;
                continue;
            }else{
                q2.push(x);
                cur_median = ( q1.top() + q2.top() ) / 2;
                cout<<floor(cur_median)<<endl;
                continue;
            }
        }else if(q1.size() == q2.size()){
            if(x < cur_median){
                q1.push(x);
                cur_median =  q1.top() ;
                cout<<floor(cur_median)<<endl;
                continue;
            }else{
                q2.push(x);
                cur_median =  q2.top() ;
                cout<<floor(cur_median)<<endl;
                continue;
            }
        }else{
            if(x < cur_median){
                q1.push(x);
                cur_median = ( q1.top() + q2.top() ) / 2;
                cout<<floor(cur_median)<<endl;
                continue;
            }else{
                int ele = q2.top();
                q2.pop();
                q1.push(ele);
                q2.push(x);
                cur_median = ( q1.top() + q2.top() ) / 2;
                cout<<floor(cur_median)<<endl;
                continue;
            }
        }
    }
    
	
	return 0;
}
