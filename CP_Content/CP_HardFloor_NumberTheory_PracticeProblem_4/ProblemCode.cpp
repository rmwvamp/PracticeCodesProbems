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

ll BinaryExponentiation_Binpow(ll base, ll exponent)
{
    ll ans = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            ans = (ans % mod) * (base % mod) % mod;
        }
        base = (base % mod) * (base % mod) % mod;
        exponent /= 2;
    }
    return ans % mod;
}

void solve()
{
    // SOLUTION STARTS
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for (ll i = 1, Rightfori; i <= n; i = Rightfori + 1)
    {
        Rightfori = n / (n / i);
        ll Quotientfori = (n / i) % mod;
        if (Quotientfori < 0)
            Quotientfori += mod;
        ll Current = BinaryExponentiation_Binpow(Quotientfori, m);
        ll CountofNumberswithSameQuotient = 1LL * (Rightfori - i + 1) % mod;
        if (CountofNumberswithSameQuotient < 0)
            CountofNumberswithSameQuotient += mod;
        Current = (Current % mod * CountofNumberswithSameQuotient % mod) % mod;
        ans = (ans % mod + Current % mod) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
