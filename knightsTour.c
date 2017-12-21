#include<stdio.h>
#include<stdlib.h>

#define N 5
void printArray(int a[N][N]){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d ",a[i][j]);

        printf("\n");
    }
    printf("\n\n");

}
int isSafe(int x,int y,int sol[N][N]){

    if(x<N && x>=0 && y>=0 && y<N && sol[x][y]==-1)
        return 1;

    return 0;

}
int moveExist(int x,int y,int move,int sol[N][N],int moveX[],int moveY[]){

    if(move==N*N)
        return 1;

    for(int i=0;i<8;i++){

        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if(isSafe(nextX,nextY,sol)){

            sol[nextX][nextY] = move;
            //printf("\n#%d#%d#%d\n",move,nextX,nextY);
            //printArray(sol);
            if(moveExist(nextX,nextY,move+1,sol,moveX,moveY)){
                return 1;
            }
            else{
                sol[nextX][nextY]=-1;
            }




        }



    }
    return 0;


}
void btsolution(){

    int sol[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            sol[i][j] = -1;

    int moveX[] =  {  2, 1, -1, -2, -2, -1,  1,  2 };
    int moveY[] = {  1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0] = 0;
    if(moveExist(0,0,1,sol,moveX,moveY)){
        printf("Path Exist\n");
        printArray(sol);
    }
    else{
        printf("Solution doesn't exist");
    }




}
int main(){

    btsolution();

}
