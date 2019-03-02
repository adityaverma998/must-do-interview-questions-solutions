/*

https://practice.geeksforgeeks.org/problems/implement-atoi/1


*/


{
 #include <bits/stdc++.h>
using namespace std;
int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this method */
int atoi(string str)
{
    //Your code here
    
    int i = 0;
    int n = 0;
    int flag = 1;
    if(str[0] == '-'){
        flag = -1;
        i = 1;
    }
    for(;str[i] != '\0';){
        if(str[i] >= '0' && str[i] <= '9'){
            n = n * 10 + (str[i++] - '0');
        }else{
            return -1;
        }
    }
    
    return (n * flag);
    
}
