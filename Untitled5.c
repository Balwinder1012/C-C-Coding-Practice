#include <bits/stdc++.h>

using namespace std;

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
        set<int> s;
        int distance[n][n];
        memset(distance,-1,sizeof(n));
        for(int i=0;i<n;i++){
            distance[i][i] = 0;
            queue<int> q;
            q.push(i);
          //  s.insert(j);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(distance[i][j]==-1 && adjMat[i][j]){

                        q.push(j);
                        distance[i][j] = distance[i][node] + y;
                     //   s.insert(j);

                    }
                }



            }

        }
    }
    return 0;
}
