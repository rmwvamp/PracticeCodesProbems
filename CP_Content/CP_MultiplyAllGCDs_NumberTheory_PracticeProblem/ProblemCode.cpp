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

vector<vector<ll>> Divisors(100100);
void DivisorsCount()
{
    for (ll i = 1; i <= ll(1e5); i++)
    {
        for (ll j = i; j <= ll(1e5); j += i)
        {
            /* code */
            Divisors[j].push_back(i);
        }
    }
}

vector<ll> FrequencyCount(100100);
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
    sci(n);
    map<ll, ll> m;
    for (int i = 0; i < n; i++)
    {
        sci(x);
        m[x]++;
    }
    for (auto v : m)
    {
        for (auto x : Divisors[v.first])
        {
            FrequencyCount[x] += v.second;
        }
    }
    for (ll i = 1; i <= 100000; i++)
    {
        FrequencyCount[i] = (BinaryExponentiation_Binpow(2, FrequencyCount[i]) - 1 + mod) % mod;
    }
    for (int i = 100000; i >= 1; i--)
    {
        for (int j = 2 * i; j <= 100000; j += i)
        {
            FrequencyCount[i] = (FrequencyCount[i] - FrequencyCount[j] + mod) % mod;
        }
    }
    ll ans = 1;
    for (int i = 2; i <= 100000; i++)
    {
        ans = ((ans % mod) * (BinaryExponentiation_Binpow(i, FrequencyCount[i]) % mod)) % mod;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    DivisorsCount();
    while (t--)
        solve();

    return 0;
}
