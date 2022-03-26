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

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a ^ b;
    else
    {
        return __gcd(a, b);
    }
}

ll n, k;
vector<ll> BaseSet(20);

int check(int x)
{
    ll ContributiontillX = 0;
    for (int SubsetMask = 1; SubsetMask < (1 << n); SubsetMask++)
    {
        // ll ContributionEachSubset = 0;
        ll CumulativeGCD = 0;
        ll CumulativeLCM = 1;
        int SubsetCountMultiplication = -1;
        for (int j = 0; j < n; j++)
        {
            if ((SubsetMask >> j) & 1)
            {
                CumulativeGCD = gcd(CumulativeLCM, 1LL * BaseSet[j]);
                CumulativeLCM = (CumulativeLCM * BaseSet[j]) / CumulativeGCD;
                SubsetCountMultiplication *= -1;
            }
        }
        ContributiontillX += SubsetCountMultiplication * (x / CumulativeLCM);
    }
    return ContributiontillX < k;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> BaseSet[i];
    }
    ll lo = 1;
    ll hi = 1e9;
    ll ans = -1;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans + 1 << endl;

    // SOLUTION STARTS
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
