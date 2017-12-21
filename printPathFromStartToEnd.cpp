#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define m 9
#define n 9

int isSafe(int x,int y){

    return x<n && y<m;
}
void printPath(list<int> &path){

    cout<<endl;
    list<int>::iterator it;
    for(it = path.begin();it!=path.end();it++){
             cout<<*it<<"-->";

    }
    cout<<"Reached"<<endl;


}

void findPathUntil(int maze[n][n],int r[],int c[],list<int> &path,int x,int y){

    if(x==n-1 && y==m-1){
        printPath(path);
        return;
    }

    for(int i=0;i<2;i++){
        int nextX = x + r[i];
        int nextY = y + c[i];

        //pair<int,int> next = make_pair(maze[nextX][nextY]);

        if(isSafe(nextX,nextY)){
            path.push_back(maze[nextY][nextX]);
            findPathUntil(maze,r,c,path,nextX,nextY);

             path.pop_back();
        }





    }

}


int findPathUntil1(int maze[n][n],int r[],int c[],list<int> &path,int x,int y){

    if(x==n-1 && y==m-1){
        printPath(path);
        return 1;
    }

    for(int i=0;i<2;i++){
        int nextX = x + r[i];
        int nextY = y + c[i];

        //pair<int,int> next = make_pair(maze[nextX][nextY]);

        if(isSafe(nextX,nextY)){
            path.push_back(maze[nextY][nextX]);
            if(findPathUntil1(maze,r,c,path,nextX,nextY))
                return 1;

             path.pop_back();
        }





    }
    return 0;

}
void findPathInMaze(int maze[n][n]){

    list<int> path;
    int row[] = {1,0};
    int col[] = {0,1};


    path.push_back(maze[0][0]);
    findPathUntil1(maze,row,col,path,0,0);


}
int main()
{
int maze[m][n] =
    {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 2, 5, 1 }
    };
    findPathInMaze(maze);

    return 0;
}
