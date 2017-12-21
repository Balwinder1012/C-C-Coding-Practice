#include <bits/stdc++.h>

using namespace std;

class graph{

    int V;
    int adjMat[][]


};
int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        int m;
        long x;
        long y;
        cin >> n >> m >> x >> y;
        int adjMat[n][n];
        memset(adjMat,0,sizeof(adjMat));

        for(int a1 = 0; a1 < m; a1++){
            int city_1;
            int city_2;
            cin >> city_1 >> city_2;
            adjMat[city_1-1][city_2-1] = 1;
            adjMat[city_2-1][city_1-1] = 1;
        }
        list<vector<int>> li;
        int visited[n];
        memset(visited,0,sizeof(visited));
        for(int i=0;i<n;i++){

            visited[i] = 1;
            visitDFA(i+1);


        }


    return 0;
}
