/*

https://practice.geeksforgeeks.org/problems/relative-sorting/0

https://www.geeksforgeeks.org/sort-array-according-order-defined-another-array/

algo-

Method 3 (Use Hashing)
1. Loop through A1[], store the count of every number in a HashMap (key: number, value: count of number) .
2. Loop through A2[], check if it is present in HashMap, if so, put in output array that many times and remove the number from HashMap.
3. Sort the rest of the numbers present in HashMap and put in output array.


ds used - map

practice map stl - 


https://www.geeksforgeeks.org/map-erase-function-in-c-stl/

https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/



code -
*/




#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        
        int n,k;
        cin>>n;
        cin>>k;
        
        int a[n];
        int b[k];
        
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<k;j++){
            cin>>b[j];
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
        
        int temp[n];
        int index = 0;
        
        for(int j=0;j<k;j++){
            auto x = m.find(b[j]);
            int no = x->second;
            while(no){
                temp[index++] = x->first;
                --no;
                m.erase(x->first);
            }
        }
        
        for(auto x = m.begin(); x != m.end(); x++){
            int no = x->second;
            while(no){
                temp[index++] = x->first;
                --no;
            }
        }
        
        for(int j=0;j<index;j++){
            cout<<temp[j]<<" ";
        }
        
        cout<<endl;
    }
    
    return 0;
}
