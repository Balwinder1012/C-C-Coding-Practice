#include<bits/stdc++.h>
using namespace std;
class Graph{

    int v;
    vector<int> *adjList;
    long long int cost;
    int vertices;
    long int clib;
    long int croad;

public:
    Graph(int n,int l,int r){
        v=n+1;
        adjList = new vector<int>[v];
        cost = 0;
        clib = l;
        croad =r;
        vertices = 0;
    }
    void addEdge(int v1,int v2){

        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }

    void dfs(){

        vector<bool> isVisited(v,false);
        for(int i=1;i<v;i++){
            if(!isVisited.at(i)){
                visitDFS(isVisited,i);
            }
             if(vertices>1){
            int roads = vertices-1;
            cost = cost + min(roads*croad + clib,vertices*clib);
            vertices=0;
            }
            if(adjList[i].size()==0){
                cost+=clib;
            }
              vertices=0;
        }
        cout<<cost<<endl;

    }
    void visitDFS(vector<bool> &isVisited,int s){
        isVisited.at(s) = true;
        vertices++;
        vector<int>::iterator it;
        for(it=adjList[s].begin();it!=adjList[s].end();it++){
            if(isVisited[*it]==false){
                visitDFS(isVisited,*it);
            }
        }


    }


};
int main(){

    int test;
    int v;
    int e;
    int clib;
    int croad;
    scanf("%d",&test);
    while(test-->0){

        scanf("%d",&v);
        scanf("%d",&e);
        scanf("%d %d",&clib,&croad);
        Graph g(v,clib,croad);
        for(int i=0;i<e;i++){
            int v1,v2;
            scanf("%d %d",&v1,&v2);
            g.addEdge(v1,v2);
        }
        g.dfs();




    }


}
