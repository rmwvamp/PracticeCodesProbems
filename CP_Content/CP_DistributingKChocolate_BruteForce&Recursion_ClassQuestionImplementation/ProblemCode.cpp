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

ll rec(ll i, ll j, ll needed)
{
    if (needed == 0)
        return 0;
    if (i * j < needed)
        return 1e15;
    if (i == j && needed == 1)
    {
        return 0;
    }
    ll ans = 1e15;
    for (int row = 1; row < i; row++)
    {
        for (int k = 0; k <= needed; k++)
        {
            ans = min(ans, rec(row, j, k) + rec(i - row, j, needed - k) + j * j);
        }
    }
    for (int col = 1; col < i; col++)
    {
        for (int k = 0; k <= needed; k++)
        {
            ans = min(ans, rec(i, col, k) + rec(i, j - col, needed - k) + i * i);
        }
    }
}
void solve()
{
    // SOLUTION STARTS
    int n, m, k;
    cin >> n >> m >> k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
