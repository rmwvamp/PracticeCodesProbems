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
vector<int> is_prime(1000100, 1);
void Sieve_of_Eratosthenes(ll n)
{
    for (int i = 2; i < n; i++)
    {
        if (is_prime[i] == 1)
        {
            for (int j = i * i; j <= n; j++)
            {
                is_prime[j] = 0;
            }
        }
    }
}
void solve()
{
    // SOLUTION STARTS
    Sieve_of_Eratosthenes(1000100);
    sci(n);
    vector<vector<int>> FrequencyCount;
    for (int i = 0; i < n; i++)
    {
        sci(m);
        vector<int> TemporaryFrequencyCount(1000100, 0);

        map<ll, ll> M;
        for (int i = 0; i < m; i++)
        {
            sci(x);
            M[x]++;
        }
        for (auto v : M)
        {
            for (auto x : Divisors[v.first])
            {
                TemporaryFrequencyCount[x] += v.second;
            }
        }
        FrequencyCount.push_back(TemporaryFrequencyCount);
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
