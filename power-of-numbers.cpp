//     https://practice.geeksforgeeks.org/problems/power-of-numbers/0


using namespace std;
#define m 1000000007
int revers(int n) 
{ 
    int rev = 0; 
    while (n > 0) 
    { 
        rev = rev*10 + n%10; 
        n = n/10; 
    } 
    return rev; 
} 
long int power(long int x, unsigned long int y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return (power(x, y / 2)%m * power(x, y / 2)%m)%m; 
    else
        return (x%m * power(x, y / 2)%m * power(x, y / 2)%m)%m; 
} 
 
int main()
 {
    int t;
    cin>>t ;
    while(t--)
    {
     long int n ;
     cin>>n ;
     long int r = revers(n) ;
     cout<<power(n,r)<<endl;
    }
	return 0;
}
