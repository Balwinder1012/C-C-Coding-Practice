#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define N 5
#define For(i,a,n) for(int i=a;i<n;i++)


int isSafe(int dis[N][N],int x,int y){
    return x>=0 && x<N && y>=0 && y<N && dis[y][x]==-1;
}
int letsMove(int a,int b){

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    int distance[N][N];
    For(i,0,N)
        For(j,0,N)
            distance[i][j]=-1;
    distance[0][0]=0;
    int xMoves[] = {a,-a,a,-a,b,-b,b,-b};
    int yMoves[] = {b,-b,-b,b,a,-a,-a,a};
    while(!q.empty()){

        pair<int,int> pr = q.front();
        q.pop();
        int x = pr.first;
        int y = pr.second;
        For(i,0,8){
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(isSafe(distance,nextX,nextY)){

                q.push(make_pair(nextX,nextY));
                distance[nextY][nextX] = distance[y][x] + 1;
                if(nextX==N-1 && nextY == N-1)
                    return distance[nextY][nextX];


            }

        }



    }

    return -1;

}
int main(){


    for(int a=1;a<N;a++){
        for(int b=1;b<N;b++){
            cout<<letsMove(a,b)<<" ";
        }
        cout<<endl;
    }
    return 0;
}

