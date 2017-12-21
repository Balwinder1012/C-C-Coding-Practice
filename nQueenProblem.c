#include<stdio.h>
#include<stdlib.h>

#define N 6
void printArray(int chess[N][N]){
       for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%2d ",chess[i][j]);
            printf("\n");
       }
        printf("\n"); printf("\n"); printf("\n");
}
int isSafe(int row,int col,int chess[N][N]){

    int r=row;
    int r1=row;
    for(int i=col-1;i>=0;i--){
        if(chess[row][i]==1 || (r<N && chess[++r][i]==1 ) || (r1>0 && chess[--r1][i]==1) ){

            return 0;
        }
    }
    return 1;


}
int solveItRec(int y,int q,int chess[N][N]){
    if(q>N)
        return 1;

    for(int i=0;i<N;i++){

        if(isSafe(i,y,chess)){

            chess[i][y] = 1;
            if(solveItRec(y+1,q+1,chess)){

                return 1;
            }
            chess[i][y] = 0;
        }
    }
    return 0;

}
void queenSol(){

    int chess[N][N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
          chess[i][j]=0;



    if(solveItRec(0,1,chess))
        printArray(chess);
    else
        printf("not possible");

}
int main(){

    queenSol();


}
