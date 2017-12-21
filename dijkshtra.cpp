#include<bits/stdc++.h>
using namespace std;
class nodes{

public:
    int vertex;
    int weight;
    nodes *next;

    nodes(int v,int w){
        vertex = v;
        weight = w;
        next = NULL;
    }
};

class adjList{

public:
    nodes *head;
};
class graph{

    int vertices;
    adjList *adj;

public:
    graph(int v){
        vertices = v;
        adj = new adjList[v+1];
        for(int i=1;i<v+1;i++){
            adj[i].head = NULL;
        }
    }

    void addEdge(int v1,int v2,int weight){
        nodes *n = new nodes(v2,weight);

        if(adj[v1].head == NULL){

            adj[v1].head = n;

            return;
        }

        nodes *ptr;
        ptr = adj[v1].head;
        while(ptr->next!=NULL){
            ptr = ptr->next;

        }
        ptr->next = n;

    }

    void display(){

       for(int i=1;i<=vertices;i++){

            cout<<"Source "<<i;
            nodes *ptr;
            int i1=1;
            ptr = adj[i].head;
            while(ptr!=NULL){
                cout<<"->("<<ptr->vertex<<","<<ptr->weight<<")";


                ptr = ptr->next;

            }

            cout<<endl<<endl;

    }


    }
};
int main(){
      graph g(3);
    g.addEdge(1,3,56);
    g.addEdge(1,2,34);
    g.addEdge(3,2,65);
    g.display();

}
