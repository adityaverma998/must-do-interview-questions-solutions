#include <bits/stdc++.h>

using namespace std;
int board[1000][1000];
int n;

void printsol(){
    cout<<"[";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                cout<<j+1<<" ";
            }
        }
    }
    cout<<"] ";
}

bool issafe(int row, int col){
    int i,j;
    
    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    
    for(i=row,j=col;i>=0 && j>= 0; i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    
    for(i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    
    return true;
}

bool solvenqutil( int col){
    if(col == n){
        printsol();
        return true;
    }
    
    bool res = false;
    for(int i=0;i<n;i++){
        if(issafe(i,col)){
            board[i][col] = 1;
            res = solvenqutil(col+1) || res;
               
            board[i][col] = 0;
        }
    }
    
    return res;
}

void solvenq(){
    if(solvenqutil(0) == false){
        
        return;
    }
    return;
}

int main(){
    
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        cin>>n;
        
        memset(board,0,sizeof(board));
        
        solvenq();
        
        cout<<endl;
        
    }
    
    return 0;
}
