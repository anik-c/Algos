#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void topologicalSort(vector<vector<int>> &adjlist,vector<bool>&visited,stack<int> &st,int u){
    visited[u]=true;
    for(int &v:adjlist[u]){
        if(!visited[v]){
            topologicalSort(adjlist,visited,st,v);
        }
    }
    st.push(u);
}
int main(){
    int vertex,edge;
    cin>>vertex>>edge;
    vector<vector<int>> adjlist(vertex);
    int u,v;
    for(int i=0;i<edge;i++){
        cin>>u>>v;
        adjlist[u].push_back(v);
    }
    stack<int> st;
    vector<bool>visited(vertex,0);
    for(int i=0;i<vertex;i++){
        if(!visited[i])
        topologicalSort(adjlist,visited,st,i);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}