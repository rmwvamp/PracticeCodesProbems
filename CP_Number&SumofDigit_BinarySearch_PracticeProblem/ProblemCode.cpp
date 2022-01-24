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

int check(long long int x, long long int s, long long int n)
{
    long long int SumofDigits = 0;
    long long int m = x;
    while (m)
    {
        long long int rem = m % 10;
        SumofDigits += rem;
        m /= 10;
    }
    // cout << SumofDigits << endl;

    return (x - SumofDigits) >= s;
}

void solve()
{

    // SOLUTION STARTS
    ll n, s;
    cin >> n >> s;

    long long int lo = 1;
    long long int hi = n;
    long long int ans = 0;
    while (lo <= hi)
    {
        long long int mid = (lo + hi) / 2;
        if (check(mid, s, n))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (ans == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << n - ans + 1 << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
