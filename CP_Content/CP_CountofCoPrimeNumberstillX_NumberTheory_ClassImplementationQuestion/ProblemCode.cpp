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

vector<ll> is_prime(1000100, 1);
void Sieve_of_Eratosthenes(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i] == 1)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

vector<ll> phi(1000100);
void Phi_Totient_Function(ll n) 
{
    for (int i = 1; i <= n; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= (phi[j] / i);
            }
        }
    }
}

void solve()
{
    sci(n);
    Sieve_of_Eratosthenes(n);
    Phi_Totient_Function(n);
    sci(q);
    while (q--)
    {
        sci(num);
        cout << phi[num] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
