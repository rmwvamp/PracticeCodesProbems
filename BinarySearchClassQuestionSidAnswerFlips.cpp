#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool check(int x, vector<int> cnt, int k, int n)
{
    for (int i = 1; i <= n - x + 1; i++)
    {
        int cnt0 = cnt[i + x - 1] - cnt[i - 1];
        if (cnt0 <= k)
        {
            return true;
        }
    }
    return false;
}

void solve();

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if (v[i] == 0)
        {
            cnt[i] = 1;
        }
        cnt[i] += cnt[i - 1];
    }
    int l = 1;
    int u = n;
    int ans = 0, mid;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (check(mid, cnt, k, n))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            u = mid - 1;
        }
    }
    cout << ans << endl;
}
