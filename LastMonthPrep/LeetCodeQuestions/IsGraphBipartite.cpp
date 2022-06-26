#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool is_bipartite;

    vector<int> Visited;

    void dfs(int node, int color, vector<vector<int>> &graph)
    {
        Visited[node] = color;
        for (auto neigbour : graph[node])
        {
            if (!Visited[neigbour])
            {
                Visited[neigbour] = 1 ^ 2 ^ color;
            }
            else
            {
                if (Visited[neigbour] == Visited[node])
                {
                    is_bipartite = false;
                    break;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        Visited.assign(graph.size(), 0);

        is_bipartite = true;
        for (int i = 0; i < graph.size(); i++)
        {
            if (!is_bipartite)
            {
                break;
            }
            if (!Visited[i])
            {
                dfs(i, 1, graph);
            }
        }
        return is_bipartite;
    }
};

int main()
{

    return 0;
}
