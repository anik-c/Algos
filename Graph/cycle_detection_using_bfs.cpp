#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool dfs(vector<vector<int>> &adjlist,vector<int> &indegree){
    queue<int> q;
    q.push(0);
    int count=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        count++;
        for(int &v:adjlist[node]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    return count==adjlist.size();
}
int main(){
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
    for(int i=0;i<adjlist.size();i++){
        for(int &edges:adjlist[i]){
            indegree[edges]++;
        }
    }
    cout<<dfs(adjlist,indegree);
}
