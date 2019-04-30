//     https://practice.geeksforgeeks.org/problems/non-repeating-character/0


using namespace std;
char nonrep(string s)
{
    int ar[256]={0};
    for(int i=0; i<s.size(); i++)
    ar[s[i]]++;
    for(int i=0; i<s.size(); i++)
    {
        if(ar[s[i]]==1)
        return s[i];
    }
  
    return '1';
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int siz;
	    cin>>siz;
    string s;
    cin>>s;
    char c=nonrep(s);
    if(c=='1')
    cout<<-1<<endl;
    else 
    cout<<c<<endl;
	}
	return 0;
}
