//      https://www.geeksforgeeks.org/check-if-a-given-sequence-of-moves-for-a-robot-is-circular-or-not/

//      http://eclassesbyravindra.com/mod/page/view.php?id=6635

#include<iostream>
#define N 0
#define E 1
#define S 2
#define W 3

using namespace std;

int main()
 {
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    string s;
	    cin>>s;
	    int x = 0;
	    int y = 0;
	    int dir = N;
	    
	    for(int j=0;j<s.length();j++){
	        if(s[j] == 'L'){
	            dir = (4 + dir - 1)%4;
	        }else if(s[j] == 'R'){
	            dir = (dir + 1)%4;
	        }else if(s[j] == 'G'){
	            if(dir == N){
	                y++;
	            }
	            if(dir == W){
	                x--;
	            }
	            if(dir == S){
	                y--;
	            }
	            if(dir == E){
	                x++;
	            }
	        }
	    }
	    if(x == 0 && y == 0){
	        cout<<"Circular"<<endl;
	    }else{
	        cout<<"Not Circular"<<endl;
	    }
	    
	}
	
	return 0;
}
