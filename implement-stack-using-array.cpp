/*

https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1

*/

{
#include<bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int arr[1000];
    int top;
public:
    Stack(){top=-1;}
    int pop();
    void push(int);
};
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Stack *sq = new Stack();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* 
The structure of the class is
class Stack
{
private:
    int arr[1000];
    int top;
public:
    Stack(){top=-1;}
    int pop();
    void push(int);
};
 */
/* The method push to push element into the stack */
void Stack :: push(int x)
{
        // Your Code
        if(top == -1){
            arr[++top] = x;
            return;
        }
        arr[++top] = x;
}
/*The method pop which return the element poped out of the stack*/
int Stack :: pop()
{
        // Your Code
        if(top == -1){
            return -1;
        }
        
        if(top == 0){
            int ele = arr[top];
            top--;
            return ele;
        }
        int ele = arr[top--];
        return ele;
}
