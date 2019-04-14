/*

https://www.geeksforgeeks.org/next-greater-element/




Method 2 (Using Stack)
1) Push the first element to stack.
2) Pick rest of the elements one by one and follow the following steps in loop.
….a) Mark the current element as next.
….b) If stack is not empty, then pop an element from stack and compare it with next.
….c) If next is greater than the popped element, then next is the next greater element for the popped element.
….d) Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
….e) Finally, push the next in the stack.
3) After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.







*/



#include <stack>
#define foreach(i,a,b) for(int i=a;i<b;i++)
using namespace std;

/*
Quite an interesting problem when we want to solve it
in linear time. It seems daunting at first, but then
turns out there exists this elegant data structure - Stack.

So this is how it works:

create an array nge[n] to store the final result.
create a stack s to do our magic.
add initial element 0 (index) to the stack.

loop 'i' from 1 to n-1 do:
    store current element in cur
    while the stack is not empty:
        check if the top is less than cur
        if yes: set nge of stack top to cur and pop stack
    push i to stack
    
while stack is not empty:
    set nge of stack top to -1 and pop stack

Done! Do a dry run and check it out!
*/

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    long long int arr[n];
	    long long int nge[n];
	    foreach(i,0,n) cin>>arr[i];
	    stack<int> s;
	    s.push(0);
	    foreach(i,1,n)
	    {
	        long long int cur = arr[i];
	        while(!s.empty() && arr[s.top()]<cur)
	        {
	            nge[s.top()] = cur;
	            s.pop();
	        }
	        s.push(i);
	    }
	    
	    
	    while(!s.empty())
	    {
	        nge[s.top()] = -1;
	        s.pop();
	    }
	    foreach(i,0,n) cout<<nge[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
