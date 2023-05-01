#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
    {
        set<pair<int, int>> checkval;
        checkval.insert({target[0], target[1]});
        checkval.insert({start[0], start[1]});
        for (auto &x : specialRoads)
        {
            checkval.insert({x[2], x[3]});
            checkval.insert({x[0], x[1]});
        }

        vector<pair<int, int>> i2p(checkval.begin(), checkval.end());
        map<pair<int, int>, int> p2i;
        vector<vector<pair<int, int>>> g(n);
        for (size_t i = 0; i < i2p.size(); i++)
            p2i[i2p[i]] = i;

        int n = i2p.size();

        int d = dist(start[0], start[1], target[0], target[1]);
        int s = p2i[make_pair(start[0], start[1])];
        int t = p2i[make_pair(target[0], target[1])];

        g[s].push_back({t, d});
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        for (int i = 0; i < specialRoads.size(); i++)
        {
            int u = p2i[make_pair(specialRoads[i][0], specialRoads[i][1])];
            int v = p2i[make_pair(specialRoads[i][2], specialRoads[i][3])];
            int w = specialRoads[i][4];
            g[u].push_back({v, w});

            g[s].push_back({u, dist(start[0], start[1], specialRoads[i][0], specialRoads[i][1])});
            g[v].push_back({t, dist(target[0], target[1], specialRoads[i][2], specialRoads[i][3])});

            for (int j = 0; j < specialRoads.size(); j++)
            {
                if (i == j)
                    continue;
                int _u = p2i[make_pair(specialRoads[j][0], specialRoads[j][1])];
                int _v = p2i[make_pair(specialRoads[j][2], specialRoads[j][3])];
                int _w = specialRoads[j][4];

                g[_v].push_back({u, dist(specialRoads[j][2], specialRoads[j][3], specialRoads[i][0], specialRoads[i][1])});
                g[v].push_back({_u, dist(specialRoads[j][0], specialRoads[j][1], specialRoads[i][2], specialRoads[i][3])});
            }
        }

        D[s] = 0;
        vector<long long> D(n, 1e18);

        pq.push({0, s});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > D[u])
                continue;
            for (auto [v, w] : g[u])
            {
                if (D[v] > D[u] + w)
                {
                    D[v] = D[u] + w;
                    pq.push({D[v], v});
                }
            }
        }

        return D[t];
    }

private:
    int dist(int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    }
};