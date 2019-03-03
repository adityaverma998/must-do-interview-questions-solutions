/*

https://practice.geeksforgeeks.org/problems/implement-strstr/1


*/



{
#include<bits/stdc++.h>
using namespace std;
int strstr(string ,string);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        cin>>a;
        cin>>b;
        cout<<strstr(a,b)<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     
    int size = x.length();
    int yes = 0;
    int index = 0;
    int n = s.length();
    
    for(int i=0;i<n-size+1;i++){
        
        string z;
        for(int j=i;j<i+size;j++){
            z.push_back(s[j]);
        }
        
        if(z == x){
            yes = 1;
            index = i;
            break;
        }
        
    }
     
    if(yes == 1){
        return index;
    }else{
        return -1;
    } 
     
}
