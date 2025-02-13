//bellmanford-algo.cpp
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> adjlist;
    int u, v,wt;
    for (int i = 0; i < vertex; i++)
    {
        cin >> u >> v >>wt;
        adjlist.push_back({u,v,wt});
    }
    vector<int> dist(vertex,INT_MAX);
    dist[0]=0;
    for(int i=0;i<vertex-1;i++){
        for(int j=0;j<edge;j++){
            int u=adjlist[j][0];
            int v=adjlist[j][1];
            int wt=adjlist[j][2];
            if(dist[u]==INT_MAX) continue;
            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    bool flag=false;
    for(int j=0;j<edge;j++){
        int u=adjlist[j][0];
        int v=adjlist[j][1];
        int wt=adjlist[j][2];
        if(dist[u]==INT_MAX) continue;
        if(dist[u]+wt<dist[v]){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"Negative Cycle Detected";
    }
    else{
        for(int &ele:dist){
            cout<<ele<<" ";
        }
    }

}