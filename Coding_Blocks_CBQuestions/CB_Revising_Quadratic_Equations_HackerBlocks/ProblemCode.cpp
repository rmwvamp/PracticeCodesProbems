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

    sciii(a, b, c);
    ll Discriminant = BinaryExponentiation_Binpow(b, 2) - 4 * a * c;
    if (Discriminant >= 0)
    {
        // int flag = 0;
        // int i;
        // for (i = 2; i * i <= Discriminant; i++)
        // {
        // }
        ll SquareRootofDiscriminat = sqrt(Discriminant);
        ll Root1 = (-b + SquareRootofDiscriminat) / 2 * a;
        ll Root2 = (-b - SquareRootofDiscriminat) / 2 * a;
        Root1 == Root2 ? cout << "Real and Equal" << endl : cout << "Real and Distinct" << endl;
        Root1 > Root2 ? cout << Root2 << " " << Root1 << endl : cout << Root1 << " " << Root2 << endl;
    }
    else
    {
        cout << "Imaginary" << endl;
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
