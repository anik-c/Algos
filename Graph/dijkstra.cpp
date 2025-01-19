#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> dijkstra(vector<vector<pair<int,int>>> &adjlist,int src){
    vector<bool>visited(adjlist.size(),0);
    vector<int> dist(adjlist.size(),INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node]=true;
        for(auto &it:adjlist[node]){
            int neighbor=it.first;
            int weight=it.second;
            if(!visited[neighbor] && dist[node]+weight<dist[neighbor]){
                dist[neighbor]=dist[node]+weight;
                pq.push({dist[neighbor],neighbor});
            }
        }
    }
    return dist;
}
int main(){
    int vertex,edges;
    cin>>vertex>>edges;
    vector<vector<pair<int,int>>> adjlist(vertex);
    int u,v,weight;
    for(int i=0;i<edges;i++){
        cin>>u>>v>>weight;
        adjlist[u].push_back({v,weight});
        adjlist[v].push_back({u,weight});
    }
    vector<int> ans;
    int src=0;
    ans=dijkstra(adjlist,src);
    for(int &ele:ans){
        cout<<ele<<" ";
    }
}