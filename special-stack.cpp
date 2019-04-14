//   https://practice.geeksforgeeks.org/problems/special-stack/1

{
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function(s) below*/





void push(int a)
{
     //add code here.
     
    s.push(a);
     
}
bool isFull(int n)
{
     //add code here.
     
     if(s.size() < n){
         return 0;
     }
     return 1;
}
bool isEmpty()
{
    //add code here.
    if(s.empty()){
        return 1;
    }
    return 0;
}
int pop()
{
    int item = s.top();
    s.pop();
    return item;
    
}
int getMin()
{
   //add code here.
   int cur_min = 10000;
   
    if(s.empty()){
        return -1;
    }
   while(!s.empty()){
      
       if(cur_min > s.top()){
           cur_min = s.top();
           
       }
       s.pop();
   }
   
   return cur_min;
   
}
