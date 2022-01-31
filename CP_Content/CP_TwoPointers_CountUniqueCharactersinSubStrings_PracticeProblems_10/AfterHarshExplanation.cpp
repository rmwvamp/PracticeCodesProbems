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
    // SOLUTION STARTS
    sci(n);
    scs(s);

    vector<vector<int>> frequency(26);

    for (int i = 0; i < 26; i++)
    {
        frequency[i].pb(-1);
    }

    for (int i = 0; i < n; i++)
    {
        frequency[s[i] - 'a'].pb(i);
    }
    for (int i = 0; i < 26; i++)
    {
        frequency[i].pb(n);
    }
    ll ans = 0;

    /* Calculating Contribution of Each Alphabet */
    for (int i = 0; i < 26; i++)
    {
        for (int j = 1; j < frequency[i].size() - 1; j++)
        {
            ans += (frequency[i][j] - frequency[i][j - 1]) * (frequency[i][j + 1] - frequency[i][j]);
        }
    }

    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
