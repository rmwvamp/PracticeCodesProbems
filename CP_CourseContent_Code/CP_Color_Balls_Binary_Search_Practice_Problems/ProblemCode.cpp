#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll, pair<ll, ll>>
#define goog(tno) cout << "Case #" << tno << ": "
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
const int inf = 0;
const double eps = 0;
const int ms = 0;
const int md = 0;
#define sci(x) \
    int x;     \
    cin >> x
#define scii(x, y) \
    int x, y;      \
    cin >> x >> y
#define sciii(x, y, z) \
    long long x, y, z; \
    cin >> x >> y >> z
#define scs(s) \
    string s;  \
    cin >> s

int check(int x, map<int, int> &m, long long n, int k)
{
    return ((1LL * x * k) <= n);
}

void solve()
{
    // SOLUTION STARTS
    scii(n, k);
    map<int, int> m;
    for (int i = 0; i < n; i++) // O(nlogn)
    {
        sci(x);
        m[x]++;
    }
    int ans;
    if (m.size() >= k) // O(logn)
    {
        // 1 2 2 1 3 3
        // 1 1 2 2 3 3

        int lo = 1;
        int hi = 1e9;
        ans = 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (check(mid, m, n, k))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        cout << ans << endl;
    }
    else
    {
        cout << "0" << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
