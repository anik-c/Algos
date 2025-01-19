#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> parent;
vector<int> rank;

int find (int x) {
    if (x == parent[x]) 
        return x;

    return parent[x] = find(parent[x]);
}

void Union (int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent) 
        return;

    if(rank[x_parent] > rank[y_parent]) {
        parent[y_parent] = x_parent;
    } else if(rank[x_parent] < rank[y_parent]) {
        parent[x_parent] = y_parent;
    } else {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}
auto comparator=[&](vector<pair<int,int>> adj1,vector<pair<int,int>>adj2){
    return adj1[0].second<adj2[0].second;
};
int kruskal(vector<vector<pair<int,int>>> &adjlist){
    sort(adjlist.begin(),adjlist.end(),comparator);
    for(auto u:adjlist){
        
    }
}
int main(){
    ///             0----20-----3-----1-----4
    ///             |           |           | \      
    ///             5           5           2  4
    ///             |           |           |   \       
    ///             1-----1-----2           5--2--6
    vector<vector<pair<int, int>>> adjlist(7);
    rank.resize(7);
    adjlist[0].push_back({3, 20});
    adjlist[0].push_back({1, 5});
    adjlist[1].push_back({0, 5});
    adjlist[1].push_back({2, 1});
    adjlist[2].push_back({1, 1});
    adjlist[2].push_back({3, 5});
    adjlist[3].push_back({0, 20});
    adjlist[3].push_back({2, 5});
    adjlist[3].push_back({4, 1});
    adjlist[4].push_back({3, 1});
    adjlist[4].push_back({5, 2});
    adjlist[4].push_back({6, 4});
    adjlist[5].push_back({4, 2});
    adjlist[5].push_back({6, 2});
    adjlist[6].push_back({5, 2});
    adjlist[6].push_back({4, 4});
}