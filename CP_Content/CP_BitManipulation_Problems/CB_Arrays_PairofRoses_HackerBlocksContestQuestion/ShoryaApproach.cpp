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

bool cmp(vector<int> v1, vector<int> v2)
{
    int dif1 = abs(v1[1] - v1[0]);
    int dif2 = abs(v2[1] - v2[0]);
    return dif1 < dif2;
}
void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sci(m);
    sort(all(arr));
    int ansi = 0;
    int ansj = 0;
    int diff = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            /* code */
            if (arr[i] + arr[j] == m)
            {
                diff = min(diff, arr[j] - arr[i]);
                if (diff == arr[j] - arr[i])
                {
                    ansi = i;
                    ansj = j;
                }
            }
        }
    }

    cout << "Deepak should buy roses whose prices are " << arr[ansi] << " and " << arr[ansj] << "." << endl;
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
