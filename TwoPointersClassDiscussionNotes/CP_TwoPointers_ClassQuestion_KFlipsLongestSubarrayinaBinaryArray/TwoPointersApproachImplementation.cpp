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

/* Approach

we try to find the maximum corresponding head for the tail by using the given required condition.


 */

void solve()
{
    // SOLUTION STARTS
    scii(n, k);
    vector<int> arr(n);
    int ans;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tail = 0;
    int head = -1;
    int cnt0 = 0;
    while (tail < n)
    {
        while ((head + 1) < n && (cnt0 + (1 - arr[head + 1])) <= k)
        {
            head++;
            cnt0 += 1 - arr[head];
        }
        ans = max(ans, head - tail + 1);
        if (head >= tail)
        {
            cnt0 -= 1 - arr[tail];
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
