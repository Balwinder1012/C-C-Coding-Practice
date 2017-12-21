#include<stdio.h>
#include<stdlib.h>
#define N 4
void printArray(char a[N][N]){

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%c ",a[i][j]);

        printf("\n");
    }
    printf("\n\n");

}
int solveItRec(int x,int y,int dx,int dy,int xMove[],int yMove[],char maze[4][4]){

    if(x==dx && y==dy){

        return 1;
    }

    for(int i=0;i<2;i++){

        int nextX = x + xMove[i];
        int nextY = y + yMove[i];
        if(nextX<4 && nextY<4 && maze[nextY][nextX]=='_'){

            maze[nextY][nextX]= '$';

            if(solveItRec(nextX,nextY,dx,dy,xMove,yMove,maze))
                return 1;
            else{
                 maze[nextY][nextX]= '#';
            }

        }

    }
    return 0;

}
void solveMaze(char maze[]){

    int xMove[] = {1,0};
    int yMove[] = {0,1};

    if(solveItRec(0,0,3,3,xMove,yMove,maze))
        printArray(maze);
    else
    printf("not possible");
}
int main()
{
    char maze[N][N]  =  {{'$', '_', '_', '#'},
                        {'_', '_', '#', '_'},
                        {'#', '_', '#', '#'},
                        {'_', '_', '_', '_'}};
 printArray(maze);
    solveMaze(maze);
    return 0;
}
