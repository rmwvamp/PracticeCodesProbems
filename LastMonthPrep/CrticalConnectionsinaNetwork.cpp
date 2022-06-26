
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> Graph;
    vector<vector<int>> Bridges;

    void dfs(int u, vector<int> &DiscoveryTime, vector<int> &LowTime, vector<int> &Parent)
    {

        static int time = 0;
        DiscoveryTime[u] = LowTime[u] = time;
        time++;
        for (int v : Graph[u])
        {
            if (DiscoveryTime[v] == -1)
            {
                Parent[v] = u;
                dfs(v, DiscoveryTime, LowTime, Parent);
                LowTime[u] = min(LowTime[u], LowTime[v]);
                if (LowTime[v] > DiscoveryTime[u])
                {
                    Bridges.push_back(vector<int>{u, v});
                }
            }
            else if (v != Parent[u]) // edge already visited,  we get a back edge
            {
                LowTime[u] = min(LowTime[u], DiscoveryTime[v]);
            }
        }
    }
    void FindBridges_using_Tarjans(int n)
    {

        vector<int> DiscoveryTime(n, -1), LowTime(n, -1), Parent(n, -1);
        // Applying DFS For Each Component

        for (int i = 0; i < n; i++)
        {
            if (DiscoveryTime[i] == -1)
            {
                dfs(i, DiscoveryTime, LowTime, Parent);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        Graph.clear();
        Graph.resize(n);
        for (int i = 0; i < connections.size(); i++) // created an adjacency list
        {
            Graph[connections[i][0]].push_back(connections[i][1]);
            Graph[connections[i][1]].push_back(connections[i][0]);
        }

        FindBridges_using_Tarjans(n);
        return Bridges;
    }
};