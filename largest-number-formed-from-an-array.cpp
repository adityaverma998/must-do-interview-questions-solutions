/*


https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0

*/


#include <bits/stdc++.h>

using namespace std;

int compare(string x, string y){
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx) > 0 ? 1 : 0;
}

void print(vector <string> arr){
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
    cout<<endl;
}

int main(){
    
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
    vector <string> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    
    print(arr);
    
    }
    return 0;
}
