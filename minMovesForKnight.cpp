
#include<iostream>
#include<bits/stdc++.h>
#define N 8
using namespace std;
#define For(i,a,n) for(int i=a;i<n;i++)
#define qi queue<pair<int,int>>
int xMoves[] = {1,2,2,1,-1,-2,-2,-1};
int yMoves[] = {-2,-1,1,2,-2,-1,1,2};
int isSafe(int mat[N][N],int x,int y){

    return x>=0 && x<N && y>=0 && y<N && mat[y][x]==-1;

}
void printArray(int mat[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<mat[i][j]<<"  ";
        cout<<endl;
    }

}
int letsMove(int distance[N][N],int x,int y){

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));

    For(i,0,N)
        For(j,0,N)
            distance[i][j]=-1;
    distance[0][0]=0;

    while(!q.empty()){

        pair<int,int> pr = q.front();
        q.pop();
        int x = pr.first;
        int y = pr.second;
        for(int i=0;i<8;i++){
             int nextX = x+xMoves[i];
             int nextY = y+yMoves[i];
            if(isSafe(distance,nextX,nextY)){



                q.push(make_pair(nextX,nextY));
                distance[nextY][nextX] = distance[y][x]+1;
                 if(nextX==N-1 && nextY==N-1){
                    printArray(distance);
                    return distance[nextY][nextX];
                }

            }

        }



    }
    return 0;
}
int main(){

    int mat[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            mat[i][j]=0;

    mat[0][0]=0;

        cout<<letsMove(mat,0,0);



}
