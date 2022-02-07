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

vector<ll> Factorials(int(1e6 + 1));
vector<ll> InverseofFactorials(int(1e6 + 1));

ll BinaryExponentiation(ll base, ll exponent)
{
    ll ans = 1;
    while (exponent)
    {
        if (exponent % 2)
            ans = ans % mod * (base % mod) % mod;
        base = (base % mod * base % mod) % mod;
        exponent /= 2;
    }
    return ans % mod;
}

void PreComputing_Factorials()
{
    Factorials[0] = 1;
    for (int i = 1; i < 1e6 + 1; i++)
    {
        /* code */
        Factorials[i] = (((Factorials[i - 1] % mod) * (i % mod) % mod));
    }

    // cout << Factorials[10] << endl;
}

void PreComputing_InversesofFactorials()
{
    InverseofFactorials[0] = 1;
    for (int i = 1; i < 1e6 + 1; i++)
    {
        /* code */
        InverseofFactorials[i] = BinaryExponentiation(Factorials[i], mod - 2);
    }
    // for (int i = 0; i < 100; i++)
    // {
    // cout << InverseofFactorials[10] << endl;
    // }
}

void solve()
{
    // SOLUTION STARTS
    scii(n, c1);
    scii(c2, c3);
    ll Result = ((((Factorials[n] % mod) * (InverseofFactorials[c1] % mod)) % mod * ((InverseofFactorials[c2] % mod) % mod) * (InverseofFactorials[c3] % mod) % mod));
    cout << Result << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << BinaryExponentiation(10, 3) << endl;
    // BinaryExponentiation(2, 2);
    PreComputing_Factorials();
    PreComputing_InversesofFactorials();
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
