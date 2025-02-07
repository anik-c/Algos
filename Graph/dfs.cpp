#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &adjlist,vector<bool>&visited,int u){
    visited[u]=true;
    cout<<u<<" ";
    for(int &v:adjlist[u]){
        if(!visited[v]){
            dfs(adjlist,visited,v);
        }
    }
}
int main(){
    vector<vector<int>> adjlist = {
        {1},
        {0,2,3},     
        {1,4}, 
        {1,4},
        {2,3},   
    };
    vector<bool>visited(adjlist.size(),0);
    dfs(adjlist,visited,0);
}