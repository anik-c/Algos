#include <iostream>
#include <vector>
using namespace std;
int find(int x, vector<int> &parent)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x], parent);
}
void Union(int a, int b, vector<int> &parent,vector<int> &rank)
{
    int a_parent = find(a, parent);
    int b_parent = find(b, parent);
    if (a_parent == b_parent)
    {
        return;
    }
    else if (rank[a_parent] > rank[b_parent])
    {
        parent[b_parent] = a_parent;
    }
    else if (rank[b_parent] > rank[a_parent])
    {
        parent[a_parent] = b_parent;
    }
    else{
        parent[b_parent]=a_parent;
        rank[a_parent]++;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> parent(n);
    vector<int> rank(n,0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    Union(0, 1, parent,rank);
    Union(3, 4, parent,rank);
    Union(0, 3, parent,rank);
}