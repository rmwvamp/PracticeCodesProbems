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
    vector<int> vi;
    int n;
    cin >> n;
    while (n--)
    {
        /* code */
        int x;
        vi.push_back(x);
    }
    vector<int> count(32, 0);
    // vector<pair<int, int>> prefixsum;
    int prefixsum[n][31] = {0};
    for (int i = 0; i < n; i++) // O(N*31)
    {

        for (int j = 0; j < 31; j++)
        {
            /* code */
            if (vi[i] & (1 << j))
            {
                // prefixsum.push_back(make_pair(vi[i][j], ))
                prefixsum[i][j]++;
            }
        }
    }
    
    for (int i = 0; i < 31; i++) // Creating a 2-D prefix counting number of 1's
    {

        for (int row = 0; row < n; row++)
        {
            /* code */

            if (row == 0)
            {
                prefixsum[i][row] = count[i];
            }
            continue;
            prefixsum[i] += count[i] + prefixsum[i - 1];
        }
    }
    // for (int i = 0; i < 31; i++) // Creating prefix counting number of 1's
    // {
    //     if (i < 1)
    //     {
    //         prefixsum[i] = count[i];
    //         continue;
    //     }
    //     prefixsum[i] += count[i] + prefixsum[i - 1];
    // }

    vector<pair<int, int>> query;
    int q;
    cin >> q;
    while (q--)
    {
        // scii(x, y);
        // query.pb({x, y});
        int l, r;
        cin >> l >> r;
        float temp = (r - l - 2 * (r - l - prefixsum[r] - prefixsum[l - 1])) / 2.0;
        int bitcontribution;
        if (temp >= 1)
        {
            bitcontribution = 1;
        }
        else
        {
            bitcontribution = 0;
        }

        /* code */
    }

    // SOLUTION STARTS
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
