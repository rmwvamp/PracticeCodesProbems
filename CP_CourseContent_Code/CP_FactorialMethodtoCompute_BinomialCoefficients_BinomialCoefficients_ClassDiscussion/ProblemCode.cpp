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

vector<ll> Factorial(1e6);
vector<ll> InversesofFactorial(1e6);

void PreComputing_Factorial_Till_1e6()
{
    Factorial[0] = 1;
    for (int i = 1; i < 1e6; i++)
    {
        Factorial[i] = ((Factorial[i - 1] % mod) * i % mod) % mod;
    }
}

ll BinaryExponentiation(ll base, ll exponent)
{
    ll ans = 1;
    while (exponent)
    {
        if (exponent % 2 == 1)
        {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return ans % mod;
}

void PreComputing_Inverses_of_Factorial_Till_1e6()
{
    for (int i = 0; i < 1e6; i++)
    {
        InversesofFactorial[i] = BinaryExponentiation(Factorial[i], mod - 2);
    }
}

void solve()
{
    // SOLUTION STARTS
    PreComputing_Factorial_Till_1e6();
    PreComputing_Inverses_of_Factorial_Till_1e6();
    // cout << BinaryExponentiation(2, 3) << endl;
    // cout << Factorial[2] << endl;
    // cout << Factorial[4] << endl;
    // cout << Factorial[20] << endl;
    // cout << Factorial[200] << endl;
    // cout << Factorial[2000] << endl;
    // cout << endl;
    // // cout << endl;
    // cout << InversesofFactorial[1] << endl;
    // cout << InversesofFactorial[2] << endl;
    // cout << InversesofFactorial[3] << endl;
    // cout << InversesofFactorial[400] << endl;
    // cout << InversesofFactorial[20] << endl;
    // cout << InversesofFactorial[200] << endl;
    // cout << InversesofFactorial[2000] << endl;

    scii(n, r);
    ll Resultant = (((Factorial[n] * InversesofFactorial[r]) % mod) * InversesofFactorial[n - r]) % mod;
    cout << Resultant << endl;
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
