//     https://www.geeksforgeeks.org/a-boolean-matrix-question/


#include<iostream>
using namespace std;
int main()
{
	//code
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        int m;
        cin>>m;
        cin>>n;
        
        int a[m][n];
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>a[j][k];
            }
        }
        
        
        
        int row[m] = {0};
        int col[n] = {0};
        
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(a[j][k] == 1){
                    row[j] = 1;
                    col[k] = 1;
                }
            }
        }
        
        
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(row[j] == 1 || col[k] == 1){
                    a[j][k] = 1;
                }
            }
        }
        
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cout<<a[j][k]<<" ";
            }cout<<endl;
        }
        
        
    }
    	
	return 0;
}
