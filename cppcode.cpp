#include "bits/stdc++.h"
using namespace std;
using ll = long long;

// #ifdef asr_debug
// #include "dbg.hpp"
// #else
// #define dbg(...) 007
// #endif

struct edge
{
    ll A, B;
};

void dfs(int v, vector<vector<pair<int, edge>>> &g, vector<bool> &used, edge carry, int destination, vector<edge> &ans)
{
    if (v == destination)
    {
        ans.push_back(carry);
        return;
    }
    used[v] = 1;
    for (auto [to, _edge] : g[v])
    {
        if (!used[to])
        {
            edge new_carry = carry;
            new_carry.A += _edge.A;
            new_carry.B += _edge.B;
            dfs(to, g, used, new_carry, destination, ans);
        }
    }
    used[v] = 0;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(5) << fixed;
    freopen("data_centers_hard_input.txt", "r", stdin);
    freopen("data_centers_hard_sample_final1_shoaib", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, edge>>> G(N);
    for (int i = 0; i < M; i++)
    {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--, v--;
        G[u].emplace_back(v, edge{a, b});
        G[v].emplace_back(u, edge{a, b});
    }

    vector<bool> used(N);
    vector<edge> ans;
    dfs(0, G, used, edge{0, 0}, N - 1, ans);

    using ld = long double;
    set<ld> times = {0, 24 * 60};
    // all pair intersections of ans
    for (int i = 0; i < (int)ans.size(); i++)
    {
        for (int j = i + 1; j < (int)ans.size(); j++)
        {
            if (ans[i].A == ans[j].A)
            {
                continue;
            }
            ld a1 = ans[i].A, b1 = ans[i].B;
            ld a2 = ans[j].A, b2 = ans[j].B;
            ld x = (b2 - b1) / (a1 - a2);
            if (x < 0 || x > 24 * 60)
            {
                continue;
            }
            times.insert(x);
        }
    }

    ld mx_ans = 0;
    for (auto t : times)
    {
        ld mn = 4e18;
        for (auto [a, b] : ans)
        {
            mn = min(mn, a * t + b);
        }
        mx_ans = max(mx_ans, mn);
    }

    cout << mx_ans << '\n';

    return 0;
}
