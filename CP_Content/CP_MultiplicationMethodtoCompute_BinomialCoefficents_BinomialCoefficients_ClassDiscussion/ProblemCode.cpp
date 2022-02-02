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

vector<ll> InverseofNumber(1e6, 0);
ll BinaryExponentiation(ll base, ll exponent)
{
    ll ans = 1;
    while (exponent)
    {
        if (exponent % 2 == 1)
        {
            ans = (ans % mod) * (base % mod) % mod;
        }
        base = ((base % mod) * (base % mod)) % mod;
        exponent /= 2;
    }
    return ans % mod;
}

void PreComputing_InverseofNumber()
{
    InverseofNumber[0] = 1;

    for (int i = 1; i < 1e4; i++)
    {
        InverseofNumber[i] = BinaryExponentiation(i, mod - 2);
        // cout << InverseofNumber[i];
    }
}

void solve()
{
    PreComputing_InverseofNumber();
    // cout << InverseofNumber[2] << endl;
    // cout << InverseofNumber[3] << endl;
    // cout << InverseofNumber[400] << endl;
    // cout << InverseofNumber[20] << endl;
    // cout << InverseofNumber[200] << endl;
    // cout << InverseofNumber[2000] << endl;
    // cout << 1LL * BinaryExponentiation(4, 2) << endl;
    ll n, r;
    cin >> n >> r;

    ll FinalAnswer = 1;
    for (int i = 0; i < r; i++)
    {
        FinalAnswer = ((FinalAnswer % mod) * (((n - i) % mod) * InverseofNumber[r + 1] % mod) % mod) % mod;
    }
    cout << FinalAnswer << endl;
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
