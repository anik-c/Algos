class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (parent[x] == x)
            return parent[x];
        return parent[x] = find(parent[x], parent);
    }
    void Union(int x, int y, vector<int> &parent, vector<int> &rank)
    {
        int a_parent = find(x, parent);
        int b_parent = find(y, parent);
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
        else
        {
            parent[b_parent] = a_parent;
            rank[a_parent]++;
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> rank(isConnected.size(), 0);
        vector<int> parent(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if (i == j)
                    continue;
                if (isConnected[i][j] == 1)
                {
                    Union((i), (j), parent, rank);
                }
            }
        }

        unordered_set<int> uniqueParents;
        for (int i = 0; i < isConnected.size(); i++)
        {
            uniqueParents.insert(find(i, parent));
        }

        return uniqueParents.size();
    }
};