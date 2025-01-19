#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int prims(vector<vector<pair<int, int>>> &adjlist, vector<bool> &inMST)
{
    int ans = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (inMST[node])
            continue;
        inMST[node] = 1;
        ans += weight;
        for (auto &neighbor : adjlist[node])
        {
            if (!inMST[neighbor.first])
            {
                pq.push({neighbor.second, neighbor.first}); 
            }
        }
    }
    return ans;
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
    vector<bool> inMST(7, 0);
    cout << prims(adjlist, inMST);
}