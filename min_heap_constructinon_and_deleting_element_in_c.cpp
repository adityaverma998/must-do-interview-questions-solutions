#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minheapify(int a[], int index, int size){
    int left = 2*index+1;
    int right = 2*index+2;
    int smallest = index;
    
    if(left < size && a[left] < a[index]){
        smallest = left;
    }
    if(right < size && a[right] < a[index]){
        smallest = right;
    }
    if(smallest != index){
        swap(&a[smallest],&a[index]);
        minheapify(a,index,smallest);
    }
}

void buildminheap(int a[], int size){
    int index;
    for(index = size/2 - 1; index>=0;index--){
        minheapify(a,index,size);
    }
}

void del(int a[], int index, int *size){
    if(index < *size){
        swap(&a[index],&a[*size - 1]);
        *size = *size - 1;
        minheapify(a,index,*size);
    }
}

int binarysearch(int a[], int ele,int start, int size){
    if(start < size){
        int mid = (start + size) / 2;
        if(a[mid] == ele){
            return mid;
        }
        binarysearch(a,ele,start,mid-1);
        binarysearch(a,ele,mid+1,size);
    }
}

int main(){
    int * a;
    int size ;
    cout<<"enter size : ";
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
    cout<<"enter element to delete : ";
    int ele;
    cin>>ele;
    
    int index = binarysearch(a,ele,0,size);
    cout<<"found at index : "<<index;
    
    cout<<" deleting ..... ";
    
    del(a,index,&size);
    cout<<" deleted ! \n";
    cout<<"items are : \n";
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
