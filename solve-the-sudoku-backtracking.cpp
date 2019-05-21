//       https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0

//   https://www.youtube.com/watch?v=MNQrDlaHAbw&t=3445s



#include<iostream>
#define max 9
using namespace std;

bool inrow(int sudoku[max][max], int r, int n){
    for(int i=0;i<9;i++){
        if(sudoku[r][i] == n){
            return false;
        }
    }
    return true;
}

bool incol(int sudoku[max][max], int c, int n){
    for(int i=0;i<max;i++){
        if(sudoku[i][c] == n){
            return false;
        }
    }
    return true;
}

bool inbox(int sudoku[max][max], int r, int c, int n){
    int rowstart = r - (r%3);
    int colstart = c - (c%3);
    
    for(int i = rowstart;i < (rowstart+3); i++){
        for(int j= colstart;j< (colstart+3);j++){
            if(sudoku[i][j] == n){
                return false;
            }
        }
    }
    
    return true;
}

bool canplacenum(int sudoku[max][max], int row, int col, int num){
    if(!inrow(sudoku,row,num)){
        return false;    
    }
    if(!incol(sudoku,col,num)){
        return false;
    }
    if(!inbox(sudoku,row,col,num)){
        return false;
    }
    return true;
}

bool sudokusolve(int sudoku[max][max]){
    int row = -1;
    int col = -1;
    bool isempty = false;
    
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j] == 0){
                isempty = true;
                row = i;
                col = j;
                break;
            }
        }
        if(isempty){
            break;
        }
    }
    
    if(!isempty){
        return true;
    }
    
    for(int num = 1; num <=9; num++){
        if(canplacenum(sudoku,row,col,num)){
            sudoku[row][col] = num;
            if(sudokusolve(sudoku)){
                return true;   
            }    
            sudoku[row][col] = 0;
        }
    }
    
    return false;
}


int main()
{
	//code
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    
	    int sudoku[9][9];
	    
	    for(int j=0;j<9;j++){
	        for(int k=0;k<9;k++){
	            
	            cin>>sudoku[j][k];
	        }
	    }
	    
	    sudokusolve(sudoku);
	    
	    for(int j=0;j<9;j++){
	        for(int k=0;k<9;k++){
	            cout<<sudoku[j][k]<<" ";
	        }
	        
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}
