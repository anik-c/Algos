#include <iostream>
#include <vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>>&adjlist,vector<bool>&visited,int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    cout<<u<<" ";
    while(!q.empty()){
        int root=q.front();
        q.pop();
        for(int &ele:adjlist[root]){
            if(!visited[ele]){
                visited[ele]=1;
                q.push(ele);
                cout<<ele<<" ";
            }
        }
    }
    }
int main()
{
    vector<vector<int>> adjlist = {
        {1},
        {0, 2, 3},
        {1, 4},
        {1, 4},
        {2, 3},
    };
    vector<bool> visited(adjlist.size(), 0);
    bfs(adjlist, visited, 0);
}