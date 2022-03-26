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

bool is_prime[1000100];
void Sieve_of_Eratosthenes(ll n)
{

    for (int i = 1; i <= n; i++)
    {
        is_prime[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] == 1)
        {
            for (ll j = 1LL * i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}
int n;
int ans;
vector<int> PrimeCycleNumbers;
int PossibleNumbers[21];

// Using 1 indexing for all understanding part
void rec(int DigitPlaceNumber)
{
    if (DigitPlaceNumber == n + 1)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (PossibleNumbers[i] == 0)
            PrimeCycleNumbers.push_back(i);
        for (int i = 0; i < PrimeCycleNumbers.size() - 1; i++)
        {
            // bool flag = 1;
            for (int j = i + 1; j < PrimeCycleNumbers.size(); j++)
            {
                if (is_prime[i + j] == 0)
                {
                    // flag = 0;
                    return;
                }
            }
        }
        rec(DigitPlaceNumber + 1);
    }
}
void solve()
{
    // SOLUTION STARTS

    ans = 0;
    cin >> n;
    memset(PossibleNumbers, -1, sizeof(PossibleNumbers));
    for (int i = 2; i <= n; i++)
    {
        PossibleNumbers[i] = 0;
    }
    PrimeCycleNumbers.pb(1);
    rec(2);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << is_prime[i] << endl;
    // }

    Sieve_of_Eratosthenes(1e6);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
