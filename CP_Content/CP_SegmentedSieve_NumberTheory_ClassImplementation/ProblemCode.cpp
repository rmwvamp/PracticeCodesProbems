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

vector<bool> is_prime(100100, 1);
vector<bool> is_primeinRangeAtoB(100100, 1);
void Sieve_of_Eratosthenes(ll n)
{
    // for (ll i = 1; i <= n; i++)
    // {
    //     is_prime[i] = 1;
    // }
    for (ll i = 2; i <= n; i++)
    {
        // cout << "Hello6" << endl;
        if (is_prime[i] == 1)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

void solve()
{
    ll a, b;
    cin >> a >> b;
    Sieve_of_Eratosthenes(100100);
    // cout << "Hello" << endl;
    for (ll PrimeNumber = 2; PrimeNumber * PrimeNumber <= b; PrimeNumber++)
    {
        // cout << "Hello2" << endl;
        if (is_prime[PrimeNumber] == 1)
        {
            // cout << "Hello3" << endl;
            long long CurrentMultiplication = ((a + PrimeNumber - 1) / PrimeNumber) * PrimeNumber;
            while (CurrentMultiplication <= b)   
            {
                // cout << "Hello4" << endl;
                if (CurrentMultiplication != PrimeNumber)
                {
                    // cout << "Hello5" << endl;
                    is_primeinRangeAtoB[CurrentMultiplication - a] = 0;
                }
                CurrentMultiplication += PrimeNumber;
                /* code */
            }
        }
    }
    for (ll i = 0; i <= (b - a); i++)
    {
        if (is_primeinRangeAtoB[i] == 1 && i + a != 1)
        {
            cout << i + a << " ";
        }
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
