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

ll n, m, k;
vector<ll> arr(100100);
vector<ll> brr(100100);

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a ^ b;
    else
        return __gcd(a, b);
}

int check(int x)
{
    ll LCM1 = (((brr[0] * brr[1]) / gcd(brr[0], brr[1])));
    ll LCM2 = (((LCM1 * brr[2]) / gcd(LCM1, brr[2])));
    ll CountofNumbers = (x / brr[0]) + (x / brr[1]) + (x / brr[2]) - (x / ((brr[0] * brr[1]) / gcd(brr[0], brr[1]))) - (x / ((brr[1] * brr[2]) / gcd(brr[1], brr[2]))) - (x / ((brr[0] * brr[2]) / gcd(brr[0], brr[2]))) + (x / LCM2);
    // cout << "Hello" << endl;
    return CountofNumbers < k;
}

void solve()
{
    // SOLUTION STARTS
    cin >> n >> m >> k;
    // cout << "Hello" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    int lo = 0;
    int hi = 1e9;
    int ans = -1;
    while (lo <= hi)
    {
        // cout << "Hello" << endl;
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans + 1 << endl;
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

