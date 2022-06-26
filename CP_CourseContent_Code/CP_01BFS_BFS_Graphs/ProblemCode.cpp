#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int, int>>> Graph;

vector<int> Distance;

void BFS01(int StartingPoint)
{
    Distance[StartingPoint] = 0;
    deque<int> dq;
    dq.push_back(StartingPoint);
    while (!dq.empty())
    {
        int node = dq.front();
        dq.pop_front();
        for (pair<int, int> v : Graph[node])
        {

            if (Distance[v.first] > Distance[node] + v.second)
            {
                Distance[v.first] = Distance[node] + v.second;
            }
            if (v.second == 0)
            {
                dq.push_front(v.first);
            }
            else
            {
                dq.push_back(v.first);
            }
        }
    }
}

int main()
{

    cin >> n >> m;
    Graph.resize(n + 1);
    Distance.assign(n + 1, 1000000);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graph[b].push_back(make_pair(a, c));
        Graph[a].push_back(make_pair(b, c));
    }

    return 0;
}
