//      https://www.geeksforgeeks.org/minimum-steps-reach-target-knight/


#include<iostream>
#include <queue>
#define MAX 1000
using namespace std;

struct cell{
    int x; int y; int dis;
};

struct cell * newnode(int a,int b,int d){
    struct cell * nn = (struct cell *)malloc(sizeof(struct cell));
    nn->x = a;
    nn->y = b;
    nn->dis = d;
    return nn;
}

bool isinside(int nx, int ny, int n){
    if(nx<1 || ny<1 || nx>n+1 || ny>n+1){
        return false;
    }
    return true;
}

int minno(int chess[MAX][MAX],int a,int b, int x, int y, int n){
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2}; 
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1}; 
    bool visit[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            visit[i][j] = false;
        }
    }
    
    queue <struct cell *> q;
    
    q.push(newnode(a,b,0));
    
    while(!q.empty()){
        struct cell * xx = q.front();
        q.pop();
        
        if(xx->x == x && xx->y == y){
            return xx->dis;
        }
        
        for(int i=0;i<8;i++){
            int newx = xx->x + dx[i];
            int newy = xx->y + dy[i];
            
            if(isinside(newx,newy,n) && !visit[newx][newy]){
                visit[newx][newy] = true;
                q.push(newnode(newx,newy,(xx->dis)+1));
            }
        }
    }
}

int main()
{
	//code
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
	    int n;
	    cin>>n;
	    
	    int a,b;
	    cin>>a>>b;
	    int x,y;
	    cin>>x>>y;
	    
	    int chess[MAX][MAX];
	    
	    cout<<minno(chess,a,b,x,y,n)<<endl;
	    
	}
	
	return 0;
}
