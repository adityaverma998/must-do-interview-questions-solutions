//     https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1


{
#include<bits/stdc++.h>
#define N 100
using namespace std;
int *mergeKArrays(int arr[][N],int k);
void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    int arr[N][N];
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	int *output = mergeKArrays(arr, k);
	printArray(output, k*k);
	cout<<endl;
}
	return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k
#include <bits/stdc++.h>

int *mergeKArrays(int arr[][N], int k)
{
//code here

    priority_queue <int , vector <int>, greater<int> > q;

    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            q.push(arr[i][j]);
        }
    }
    
    int * a = (int *)malloc(sizeof(int) * (k * k));
    int index = 0;
    
    for(int i=0;i<k*k;i++){
        
        a[index++] = q.top();
        q.pop();
    }

    return a;
}
