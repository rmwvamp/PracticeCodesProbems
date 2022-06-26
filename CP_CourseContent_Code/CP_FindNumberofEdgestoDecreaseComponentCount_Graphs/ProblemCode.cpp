#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> Graph; // Storing a graph using a adjacency list

vector<int> Visited;
void dfs(int node, int ComponentCounter)
{
    Visited[node] = ComponentCounter;
    for (auto v : Graph[node])
    {
        if (Visited[v] == 0)
        {
            dfs(v, ComponentCounter);
        }
    }
}

int main()
{
    cin >> n >> m;
    Graph.resize(n + 1);
    Visited.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    int counter = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!Visited[i])
        {

            dfs(i, counter++);
        }
    }

    // Doubt how to build the suffix sum

    vector<int> CountNodes(counter + 1);
    for (int i = 1; i <= n; i++)
    {
        /* code */
        CountNodes[Visited[i]]++;
    }

    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += CountNodes[i] * sum;
        sum += CountNodes[i];
    }

    return 0;
}
