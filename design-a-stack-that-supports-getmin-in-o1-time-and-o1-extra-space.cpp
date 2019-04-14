//    http://eclassesbyravindra.com/mod/page/view.php?id=3313
//     https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/




#include <bits/stdc++.h>

int cur_min = INT_MAX;

void push(int a)
{
     //add code here.
     
     
     if(s.empty()){
         s.push(a);
         cur_min = a;
         return;
     }
     
     if(cur_min > a){
         s.push(a - cur_min);
         cur_min = a;
     }
     
     if(cur_min <= a){
         s.push(a);
     }
     
}
bool isFull(int n)
{
     //add code here.
     
     if(s.size() != n){
         return 1;
     }
     return 0;
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
    //add code here.
    if(s.empty()){
        return -1;
    }
    
    if(s.top() >= cur_min){
        int item = s.top();
        s.pop();
        return item;
    }
    
    
    cur_min = cur_min - s.top();
    return cur_min;
    
    
}
int getMin()
{
   //add code here.
   
   return cur_min;
   
}
