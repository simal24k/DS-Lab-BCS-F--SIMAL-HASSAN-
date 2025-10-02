#include<iostream>
using namespace std;

int N;

void printSol(int board[20][20]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool isSafe(int board[20][20], int row, int col){
    for(int i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1) return false;
    }
    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

bool solveNQUtil(int board[20][20], int row){
    if(row==N){
        printSol(board);
        return true;
    }
    bool res=false;
    for(int col=0;col<N;col++){
        if(isSafe(board,row,col)){
            board[row][col]=1;
            res=solveNQUtil(board,row+1) || res;
            board[row][col]=0;
        }
    }
    return res;
}

void solveNQ(){
    int board[20][20]={0};
    if(!solveNQUtil(board,0)){
        cout<<"No solution exists\n";
    }
}

int main(){
    cout<<"Enter value of N:"<<endl;
    cin>>N;
    solveNQ();
    return 0;
}
