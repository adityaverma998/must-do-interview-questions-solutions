/*


https://www.geeksforgeeks.org/implement-stack-using-queue/

*/




{
#include<bits/stdc++.h>
using namespace std;
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
int main()
{
     int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";
        }
        }
        cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */
/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        // Your Code
        
        q1.push(x);
        
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        // Your Code 
        if(q1.empty()){
            return -1;
        }
        
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        
        int ele = q1.front();
        q1.pop();
        
        queue <int> q = q1;
        q1 = q2;
        q2 = q;
        
        return ele;
        
}
