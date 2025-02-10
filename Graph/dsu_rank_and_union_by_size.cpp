#include<iostream>
#include <vector>
using namespace std;
int find(int x, vector<int> &parent)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x], parent);
}
void Union(int a, int b, vector<int> &parent,vector<int> &size)
{
    int a_parent = find(a, parent);
    int b_parent = find(b, parent);
    if (a_parent == b_parent)
    {
        return;
    }
    else if (size[a_parent] > size[b_parent])
    {
        parent[b_parent] = a_parent;
        size[a_parent]+=size[b_parent];
    }
    else if (size[b_parent] > size[a_parent])
    {
        parent[a_parent] = b_parent;
        size[b_parent]+=size[a_parent];
    }
    else{
        parent[b_parent]=a_parent;
        size[a_parent]++;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> parent(n);
    vector<int> size(n,1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    Union(0, 1, parent,size);
    Union(3, 4, parent,size);
    Union(0, 3, parent,size);
    for (int i = 0; i < n; i++) {
        find(i, parent);
    }
    for (int &ele : parent)
    {
        cout << ele << " ";
    }
}