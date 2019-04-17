/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minheapify(int a[], int index, int size){
    int left = 2*index +1;
    int right = 2*index +2;
    int smallest = index;
    
    if(left < size && a[left] < a[index]){
        smallest = left;
    }
    if(right < size && a[right] < a[index]){
        smallest = right;
    }
    if(smallest != index){
        swap(&a[index],&a[smallest]);
        minheapify(a,index,smallest);
    }
}

void buildminheap(int a[], int size){
    int index;
    for(index = size/2 - 1; index >=0 ; index--){
        minheapify(a,index,size);
    }
}

int main()
{
    int * a;
    int size ;
    cout<<"enter the size : ";
    cin>>size;
    
    a = (int *)malloc(sizeof(int) * size);
    
    cout<<"enter the elements : ";
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    buildminheap(a,size);
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
