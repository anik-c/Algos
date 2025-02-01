#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(int x, vector<int> &parent)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);
    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent])
    {
        parent[y_parent] = x_parent;
    }
    else if (rank[x_parent] < rank[y_parent])
    {
        parent[x_parent] = y_parent;
    }
    else
    {
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

vector<vector<int>> spanningTree(vector<vector<pair<int, int>>> &adjlist)
{
    vector<vector<int>> adj;
    for (int u = 0; u < adjlist.size(); u++)
    {
        for (auto &neigh : adjlist[u])
        {
            int v = neigh.first;
            int wt = neigh.second;
            adj.push_back({u, v, wt});
        }
    }
    sort(adj.begin(), adj.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] < b[2]; });

    return adj;
}
int kruskal(vector<vector<pair<int, int>>> &adjlist)
{
    spanningTree(adjlist);
    vector<vector<int>> adj = spanningTree(adjlist);
    vector<int> parent(adj.size());
    vector<int> rank(adj.size(), 0);
    for (int i = 0; i < adj.size(); i++)
    {
        parent[i] = i;
    }
    int sum = 0;
    for (auto &temp : adj)
    {
        int u = temp[0], v = temp[1], wt = temp[2];
        if (find(u, parent) != find(v, parent))
        {
            Union(u, v, parent, rank);
            sum += wt;
        }
    }
    return sum;
}
int main()
{
    ///             0----20-----3-----1-----4
    ///             |           |           | \      
    ///             5           5           2  4
    ///             |           |           |   \       
    ///             1-----1-----2           5--2--6
    vector<vector<pair<int, int>>> adjlist(7);
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
    cout<<kruskal(adjlist);
}