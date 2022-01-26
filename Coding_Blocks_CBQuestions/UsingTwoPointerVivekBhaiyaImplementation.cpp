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

void solve()
{
    // SOLUTION STARTS n=1e3
    sci(n);
    vector<int> arr(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    sci(t);
    int tail = 0;
    int head = -1;
    vector<int> temp;
    while (tail < n)
    {
        int HopeSum = arr[tail] + arr[head + 1];
        while (head + 1 < n && (HopeSum <= t))
        {
            head++;
            if (HopeSum == t)
            {
                temp.pb(arr[tail]);
                temp.pb(arr[head]);
            }
        }
        if (head >= tail)
        {
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
        ans.pb(temp);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        int j = 0;
        cout << ans[i][j] << " and " << ans[i][j + 1] << endl;
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
