#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define n 9

int xCorners[] = {0,n-1,0,n-1};
int yCorners[] = {0,0,n-1,n-1};

int row[] = {0,0,1,-1};
int col[] = {-1,1,0,0};
void printPath(list<pair<int,int>> path){

    list<pair<int,int>>::iterator it;
    for(it = path.begin(); it!=path.end(); it++){
        cout<<"("<<it->first<<","<<it->second<<")-->";

    }
    cout<<"Mid"<<endl;
}
int isSafe(pair<int,int> &next,set<pair<int,int>> &visited){

    int x = next.first;
    int y = next.second;
    return x>=0 && x<n && y>=0 && y<n && visited.find(next)== visited.end();
}
void findPathUntil(int maze[n][n],list<pair<int,int>> &path,set<pair<int,int>> &visited,pair<int,int> &pt){


    if(pt.first==n/2 && pt.second==n/2){

        printPath(path);
        return;
    }

    for(int i=0;i<4;i++){

        int x = pt.first + row[i]*maze[pt.first][pt.second];
        int y = pt.second + col[i]*maze[pt.first][pt.second];

        pair<int,int> next = make_pair(x,y);

        if(isSafe(next,visited)){
            path.push_back(next);
            visited.insert(next);
            findPathUntil(maze,path,visited,next);

            path.pop_back();
            visited.erase(next);
        }
    }



}
void findPathInMaze(int maze[n][n]){

    list<pair<int,int>> path;
    set<pair<int,int>> visited;

    for(int i=0;i<4;i++){

        int x = xCorners[i];
        int y = yCorners[i];

        pair<int,int> xy = make_pair(x,y);
        path.push_back(xy);
        visited.insert(xy);
        findPathUntil(maze,path,visited,xy);

        path.pop_back();
        visited.erase(xy);
    }


}
int main()
{
    int maze[n][n] =
    {
        { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
        { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
        { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
        { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
        { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
        { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
        { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
        { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
        { 6, 2, 4, 3, 4, 5, 4, 5, 1 }
    };

    findPathInMaze(maze);

    return 0;
}
