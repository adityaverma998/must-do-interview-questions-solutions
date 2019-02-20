
//   https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station-set-2-map-based-approach/

#include <bits/stdc++.h>

using namespace std;

int platform(int a[], int d[], int n){
    multimap < int, char > m;
    
    for(int i=0;i<n;i++){
        m.insert(make_pair(a[i],'a'));
        m.insert(make_pair(d[i],'d'));
    }
    
    int result = 0;
    int plat = 0;
    
    for(auto i = m.begin();i!=m.end();i++){
        if((*i).second == 'a'){
            ++plat;
        }else{
            --plat;
        }
        if(plat > result){
            result = plat;
        }
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        int n;
        cin>>n;
        int a[n];
        int d[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>d[i];
        }
        int p = platform(a,d,n);
        cout<<p<<endl;
    }
    return 0;
}
