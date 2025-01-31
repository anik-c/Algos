#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void kahns(vector<vector<int>>&adjlist,vector<int> &indegree){
    queue<int> q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(int &v:adjlist[node]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
}
int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<int>> adjlist(vertex);
    int u, v;
    for (int i = 0; i < edge; i++)
    {
        cin >> u >> v;
        adjlist[u].push_back(v);
    }
    vector<int> indegree(vertex);
    for(int i=0;i<vertex;i++){
        for(int &v:adjlist[i]){
            indegree[v]++;
        }
    }
    kahns(adjlist,indegree);
}