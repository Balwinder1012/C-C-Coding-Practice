#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define N 4
int xMoves[] = {1,2,2,1,-1,-2,-2,-1};
int yMoves[] = {-2,-1,1,2,-2,-1,1,2};
int minMoves = N*N;
int isSafe(int mat[N][N],int x,int y){

    return x>=0 && x<N && y>=0 && y<N && mat[y][x]==0;

}

void printArray(int mat[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }

}
void letsMove(int mat[N][N],int x,int y,int count){
    if(x==N-1 && y==N-1){
        if(minMoves>count){
            printArray(mat);
            cout<<endl;
            minMoves = count;
        }
        else{
            cout<<"more moves ";
        }
        return;
    }
    for(int i=0;i<8;i++){

        int nextX = x + xMoves[i];
        int nextY = y + yMoves[i];

        if(isSafe(mat,nextX,nextY)){
            mat[nextY][nextX] = count;
            letsMove(mat,nextX,nextY,count+1);
            mat[nextY][nextX] = 0;
        }





    }


}

int main(){

    int mat[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            mat[i][j]=0;

    mat[0][0]=1;
    letsMove(mat,0,0,2);


}
