#include <bits/stdc++.h>
using namespace std;
int vertices, edges_connections;

vector<vector<pair<int, int>>> GraphAdjacencyList;

vector<long long> Distance;

// first value-> node, second edge

vector<int> Visited;

class Priortise
{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int StartingPoint)
{
    for (int i = 1; i <= vertices; i++)
    {
        Distance[i] = 1e18;
        Visited[i] = 0;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, Priortise> pq;
    Visited[StartingPoint] = 1;
    Distance[StartingPoint] = 0;
    pq.push({StartingPoint, 0});
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        if (Visited[node.first])
            continue;
        Visited[node.first] = 1;

        for (pair<int, int> v : GraphAdjacencyList[node.first])
        {
            int neighbor = v.first;
            int weight = v.second;
            if (Distance[neighbor] > Distance[node.first] + weight)
            {
                Distance[neighbor] = Distance[node.first] + weight;
                pq.push({neighbor, Distance[neighbor]});
            }
        }
    }
}

void dijkstra_withoutusingClass(int StartingPoint)
{
    for (int i = 1; i <= vertices; i++)
    {
        Distance[i] = 1e18;
        Visited[i] = 0;
    }

    priority_queue<pair<int, int>> pq;
    Visited[StartingPoint] = 1;
    Distance[StartingPoint] = 0;
    pq.push({-0, StartingPoint});
    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        pq.pop();
        if (Visited[node.second])
            continue;
        Visited[node.second] = 1;

        for (pair<int, int> v : GraphAdjacencyList[node.second])
        {
            int neighbor = v.second;
            int weight = v.first;
            if (Distance[neighbor] > Distance[node.second] + weight)
            {
                Distance[neighbor] = Distance[node.second] + weight;
                pq.push({-Distance[neighbor], neighbor});
            }
        }
    }
}

int main()
{
    cin >> vertices >> edges_connections;
    for (int i = 0; i < edges_connections; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        GraphAdjacencyList[a].push_back(make_pair(b, c));
        GraphAdjacencyList[b].push_back(make_pair(a, c));
    }
    int StartingPoint;
    cin >> StartingPoint;
    // dijkstra(StartingPoint);

    return 0;
}
