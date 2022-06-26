#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Graph;

vector<int> Visited;

bool Bipartite;

void dfs(int node, int Color)
{
    Visited[node] = Color;

    for (auto v : Graph[node])
    {
        if (!Visited[v])
        {
            // dfs(v, 3 - Color);
            dfs(v, 1 ^ 2 ^ Color);
        }
        else
        {
            if (Visited[v] == Visited[node])
            {
                Bipartite = false;
                break;
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    Graph.clear();

    Graph.resize(n + 1);
    Visited.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    Bipartite = true;
    for (int i = 1; i <= n; i++)
    {
        if (!Visited[i])
        {
            dfs(i, 1);
        }
        if (!Bipartite)
        {
            break;
        }
    }

    cout << Bipartite << endl;

    return 0;
}
