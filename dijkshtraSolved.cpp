#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int,int>> vii;

class graph
{

    int vertices;
    vii *adjList;
    pair<int,int> *dist;

public:
    graph(int v)
    {
        vertices = v;
        adjList = new vii[v+1];
        dist = new pair<int,int>[v+1];

        for(int i=1; i<=v; i++)
        {
            dist[i].first = i;
            dist[i].second = INT_MAX;

        }
        dist[1].second = 0;
    }

    void addEdge(int v1,int v2,int weight)
    {

        adjList[v1].push_back(make_pair(v2,weight));


    }
    void display()
    {

        for(int i=1; i<=vertices; i++)
        {
            cout<<endl<<"Source "<<i;
            vector<pair<int,int>>::iterator it;
            for(it=adjList[i].begin(); it!=adjList[i].end(); it++)
            {
                cout<<"("<<it->first<<","<<it->second<<")";
            }
        }
    }
    int lchild(int i)
    {
        return i*2;
    }
    int rchild(int i)
    {
        return i*2+1;
    }
    void swap_(int i,int j)
    {
        int temp = dist[i].second;
        dist[i].second =dist[j].second;
        dist[j].second = temp;

        temp = dist[i].first;
        dist[i].first = dist[j].first;
        dist[j].first = temp;
    }
    void heapify(int i,int heapSize)
    {
        int l = lchild(i);
        int r = rchild(i);
        int smallest = i;


        if(l<=heapSize && dist[l].second<dist[i].second)
            smallest = l;
        else if(r<=heapSize && dist[r].second < dist[smallest].second)
        {
            smallest = r;
        }
        if(smallest!=i)
        {
            swap_(i,smallest);
            heapify(smallest,heapSize);

        }

    }
    void relaxEdge(int v,int wuv,int s,int heapSize)
    {

        int index;
        bool found = false;


        for(int i=1; i<=heapSize; i++)
        {
            if(v==dist[i].first)
            {
                found = true;
                index =i;
            }


        }
        if(found==false)
        {

            return;
        }



        if(dist[index].second > wuv + s)
        {
            dist[index].second = wuv +s;

            heapifyUp(index,heapSize);
        }



    }
    int getParent(int i)
    {
        return (i-1)/2;
    }
    int hasParent(int i,int n)
    {
        return (i-1)/2 >=1 ? 1:0;
    }
    void heapifyUp(int i,int n)
    {

        int d=i;
        while(hasParent(i,n))
        {

            int pv = dist[getParent(i)].second;


            if(pv>dist[i].second)
            {
                swap_(getParent(i),i);
                i = getParent(i);


            }
            else
                break;

        }



    }

//implementing dijkshtra
    pair<int,int> *extractMin(int n)
    {



        pair<int,int> *temp;
        temp = new pair<int,int>();
        temp->first = dist[1].first;
        temp->second = dist[1].second;
        dist[1].first = dist[n].first;
        dist[1].second = dist[n].second;
        dist[n].first = temp->first;
        dist[n].second = temp->second;
        heapify(1,n-1);



        return temp;
    }
    void findShortestPath()
    {

        int queCounter = 0;

        int heapSize = vertices;
        while(queCounter!=vertices)
        {

            pair<int,int> *extMin = extractMin(heapSize);

            queCounter++;
            heapSize--;

            for(vii::iterator it=adjList[extMin->first].begin(); it!=adjList[extMin->first].end(); it++)
            {

                relaxEdge(it->first/*v*/,it->second/*w(u,v)*/,extMin->second/*d[s]*/,heapSize);

            }

        }

        for(int i=vertices; i>=1; i--)
        {

            cout<<dist[i].first<<"  at distance "<<dist[i].second<<endl;

        }







    }
};

int main()
{
    graph g(6);
    g.addEdge(1,3,56);
    g.addEdge(1,2,34);
    g.addEdge(3,2,65);
    g.addEdge(3,5,12);
    g.addEdge(2,5,33);
    g.addEdge(2,4,67);
    g.addEdge(4,1,4);
    g.addEdge(5,6,14);
    g.display();
    cout<<endl<<endl;
    g.findShortestPath();

}

