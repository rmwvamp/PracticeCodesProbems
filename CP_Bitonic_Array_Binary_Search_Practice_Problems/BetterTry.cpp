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

int checkMaxBitonicArray(int x, int n, vector<int> &v)
{
    return v[x] > v[x - 1];
}

int check(int x, vector<int> &v, int value)
{
    return v[x] >= value;
}
void solve()
{
    scii(n, q);
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int lo = 2;
    int hi = n;
    int ans = 1;
    while (lo <= hi)
    {
        /* code */
        int mid = (lo + hi) / 2;
        if (checkMaxBitonicArray(mid, n, v))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << ans << endl;
    // int ansloop1 = 0, ansloop2 = 0;
    // vector<int> queries(q, 0);
    // for (int i = 0; i < q; i++)
    // {
    //     cin >> queries[i];
    // }

    // for (int j = 0; j < q; j++)
    // {
    //     int value = queries[j];

    //     int begin = 1;
    //     int end = ans;
    //     ansloop1 = 1;
    //     while (begin <= end)
    //     {
    //         int mid = (begin + end) / 2;
    //         if (check(mid, v, value))
    //         {
    //             ansloop1 = mid;
    //             hi = mid - 1;
    //         }
    //         else
    //         {
    //             lo = mid + 1;
    //         }
    //     }
    //     if (v[ansloop1] == value)
    //     {
    //         cout << ansloop1 << " ";
    //     }
    //     int head = ans + 1;
    //     int tail = n;
    //     ansloop2 = 1;
    //     while (head <= tail)
    //     {
    //         int mid = (head + tail) / 2;
    //         if (check(mid, v, value))
    //         {
    //             ansloop2 = mid;
    //             head = mid + 1;
    //         }
    //         else
    //         {
    //             tail = mid - 1;
    //         }
    //     }
    //     if (v[ansloop2] == value)
    //     {
    //         cout << ansloop2 << endl;
    //     }
    //     else
    //     {
    //         cout << endl;
    //     }
    // }
}

// cout << ansloop1 << " " << ansloop2 << endl;
// }

// SOLUTION STARTS

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
