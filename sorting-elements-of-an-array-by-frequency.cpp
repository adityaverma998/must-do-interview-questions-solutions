/*

https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0


You can't sort a std::map this way (using its value in ascending order) because the map's entries are sorted by the key. What you can do is transfer the entries to a std::vector and then sort it in ascending order, like:

std::vector<std::pair<double, double>> mapVector;
std::map<double, double> map1;
// Insert entries
for (auto iterator = map1.begin(); iterator != map1.end(); ++iterator {
mapVector.push_back(*iterator);
}
sort(mapVector.begin(), mapVector.end());



https://www.quora.com/How-can-one-sort-a-map-using-its-value-in-ascending-order





*/


#include<bits/stdc++.h>

using namespace std;

bool compare(pair <int , int> p, pair <int , int >q){
    if(p.second > q.second){
        return 1;
    }else if(p.second == q.second){
        if(p.first < q.first){
            return 1;
        }
    }
    return 0;
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
	    
	    map < int , int > m;
	    for(int j=0;j<n;j++){
	        if(m.find(a[j]) != m.end()){
	            auto x = m.find(a[j]);
	            (x->second)++;
	        }else{
	            m.insert(make_pair(a[j],1));
	        }
	    }
	    
	    vector < pair <int , int > > v;
	    for(auto x = m.begin(); x != m.end(); x++){
	        v.push_back(make_pair(x->first,x->second));
	    }
	    
	    sort(v.begin(),v.end(),[](pair < int , int > p, pair < int, int > q){return ( compare(p , q) );});
	    
	    for(auto x = v.begin(); x != v.end();x++){
	        int no = x->second;
	        while(no){
	            cout<<x->first<<" ";
	            --no;
	        }
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
