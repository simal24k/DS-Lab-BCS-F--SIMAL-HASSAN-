#include<iostream>
using namespace std;

int N = 5;

bool isSafe(int maze[5][5], int x, int y, int sol[5][5]){
    if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1 && sol[x][y]==0){
        return true;
    }
    return false;
}

bool solveMazeUtil(int maze[5][5], int x, int y, int sol[5][5]){
    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }

    if(isSafe(maze,x,y,sol)){
        sol[x][y]=1;

        
        if(solveMazeUtil(maze,x,y+1,sol)){
            return true;
        }
        
        if(solveMazeUtil(maze,x+1,y,sol)){
            return true;
        }
        
        if(solveMazeUtil(maze,x,y-1,sol)){
            return true;
        }
        
        if(solveMazeUtil(maze,x-1,y,sol)){
            return true;
        }

        sol[x][y]=0; 
    }
    return false;
}

bool solveMaze(int maze[5][5]){
    int sol[5][5]={{0}};
    if(solveMazeUtil(maze,0,0,sol)==false){
        cout<<"No solution exists"<<endl;
        return false;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<"\n";
    }
    return true;
}

int main(){
    int maze[5][5] = { {1, 0, 0, 0, 0},
                       {1, 1, 0, 1, 0},
                       {0, 1, 0, 0, 0},
                       {1, 1, 1, 1, 0},
                       {0, 0, 0, 1, 1} };

    solveMaze(maze);
    return 0;
}
