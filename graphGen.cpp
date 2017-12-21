#include<bits/stdc++.h>
using namespace std;

class Graph{

    int v;
    vector<int> *adjList;
    int vectorCounter;
    unordered_map<int,int> vertMap;

public:
    Graph(int n){
        v=n;
        vectorCounter=0;
        adjList = new vector<int>[v+1];
    }
    void addEdge(int v1,int v2){

        unordered_map<int,int>::iterator it1;
        it1=vertMap.find(v1);
        int av;
        if(it1==vertMap.end()){
              vertMap.insert(make_pair(v1,vectorCounter+1));
                vectorCounter++;
                av=vectorCounter;
        }

        else{

             av=it1->second;

        }

        it1=vertMap.find(v2);
        int bv;
        if(it1==vertMap.end()){
              vertMap.insert(make_pair(v2,vectorCounter+1));
                bv=vectorCounter+1;
                vectorCounter++;
        }

        else{
             bv=it1->second;
        }





        adjList[av].push_back(bv);
        adjList[bv].push_back(av);


    }
    void printVertices(){
        unordered_map<int,int>::iterator it1;
       for(it1=vertMap.begin();it1!=vertMap.end();it1++){
            cout<<it1->first<<" "<<it1->second<<endl;


        }
    }

    void dfs(){

        vector<bool> isVisited(v+1,false);

        for(int i=1;i<=v;i++){
            if(!isVisited.at(i)){
                visitDFS(isVisited,i);
            }


    }
    }
    void visitDFS(vector<bool> &isVisited,int s){

        isVisited.at(s) = true;

        unordered_map<int,int>::iterator it1;
        for(it1=vertMap.begin();it1!=vertMap.end();it1++){
            if(it1->second==s){
                cout<<it1->first<<endl;
                break;
            }
        }

        vector<int>::iterator it;
        for(it=adjList[s].begin();it!=adjList[s].end();it++){
            if(isVisited[*it]==false){
                visitDFS(isVisited,*it);
            }
        }


    }


};
int main(){

    int vertices = 5;
    Graph g(vertices);
    g.addEdge(56,789);
    g.addEdge(789,12);
    g.addEdge(45,56);
    g.addEdge(12,100);
    g.printVertices();
    g.dfs();

    return 0;
}
