#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define for(i,a,n) for(int i=a;i<n;i++)
#define forAllNumbers for(int i=1;i<=9;i++)
#define Unassigned 0

#define match(i,j,elem) if(grid[i][j]==elem)
int _r=0;
int _c=0;
void printGrid(int grid[9][9]){
    for(i,0,9){
        for(j,0,9)
            printf("%2d  ",grid[i][j]);
        printf("\n");
    }
}

int notInRow(int grid[9][9],int row,int elem){

    for(i,0,9){
        if(grid[row][i]==elem)
            return 0;
    }
    return 1;

}
int notInCol(int grid[9][9],int col,int elem){
    for(i,0,9)
        if(grid[i][col]==elem)
            return 0;
    return 1;
}

int notInSGrid(int grid[9][9],int i,int j,int elem){
    //1
    if(i<3 && j<3){

        for(m,0,3)
            for(n,0,3)
                match(m,n,elem)
                    return 0;


    }
    //2
    else if(i<3 && j>=3 && j<6){
             for(m,0,3)
                for(n,3,6)
                    match(m,n,elem)
                        return 0;

    }
    //3
    else if(i<3 && j>5){
         for(m,0,3)
            for(n,6,9)
                match(m,n,elem)
                    return 0;



    }
    //4
    else if(i>=3 && i<6 && j<3){
         for(m,3,6)
            for(n,0,3)
                match(m,n,elem)
                    return 0;



    }
    //5
    else if(i>=3 && i<6 && j>=3 && j<6 ){
         for(m,3,6)
            for(n,3,6)
                match(m,n,elem)
                    return 0;


    }
    //6
    else if(i>=3 && i<6 && j>=6){

         for(m,3,6)
            for(n,6,9)
                match(m,n,elem)
                    return 0;

    }
    //7


     else if(i>=6 && j<3){
         for(m,6,9)
            for(n,0,3)
                match(m,n,elem)
                    return 0;



    }
    //8
    else if(i>=6 && j>=3 && j<6 ){
         for(m,6,9)
            for(n,3,6)
                match(m,n,elem)
                    return 0;


    }
    //9
    else{
            for(m,6,9)
                for(n,6,9)
                    match(m,n,elem)
                        return 0;


    }
    return 1;


}

int isSafe(int grid[9][9],int i,int j,int elem){

    return notInRow(grid,i,elem) && notInCol(grid,j,elem) && notInSGrid(grid,i,j,elem);
}

int isStillEmpty(int grid[][9],int &p,int &q){

    for(i,0,9)
        for(j,0,9)
            if(grid[i][j]==Unassigned){
                _r = p = i;
                _c = q = j;

                return 1;
            }
    return 0;
}
int SolveSuduko(int grid[9][9],int i,int j){

    if(!isStillEmpty(grid,i,j)){

        return 1;

    }
    for(elem,1,10){
        if(isSafe(grid,i,j,elem)){

            grid[i][j] = elem;
            if(SolveSuduko(grid,i,j)){
                return 1;
            }
            grid[i][j]= 0;

        }



        }
    return 0;
}
int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSuduko(grid,0,0))
          printGrid(grid);
    else
         printf("No solution exists");

    return 0;
}
