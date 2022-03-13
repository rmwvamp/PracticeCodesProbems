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

// vector<ll> arr;
vector<ll> SubsetSum(vector<ll> arr, ll n)
{
    vector<ll> ans;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)))
            {
                sum += arr[i];
            }
        }
        ans.pb(sum);
    }
    sort(all(ans));
    return ans;
}

void solve()
{
    int n = 3, x = 5;
    vector<ll> v = {1, 2, 3};
    vector<ll> a, b;
    for (int i = 0; i < n; i++)
    {
        if (i % 2)
        {
            a.pb(v[i]);
        }
        else
        {
            b.pb(v[i]);
        }
    }
    vector<ll> SubsetSumA = SubsetSum(a, a.size());
    vector<ll> SubsetSumB = SubsetSum(b, b.size());
    ll ans = 0;
    for (auto v : SubsetSumA)
    {
        ans += upper_bound(SubsetSumB.begin(), SubsetSumB.end(), x - v) - SubsetSumB.begin();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
    