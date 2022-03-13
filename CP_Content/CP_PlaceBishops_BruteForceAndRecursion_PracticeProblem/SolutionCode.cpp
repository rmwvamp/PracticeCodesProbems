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

#define REP(i, n) for (int i = 0; i < n; i++)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define ALLL(x) x.begin(), x.end()
#define SORT(x) sort(ALLL(x))
#define CLEAR(x) memset(x, 0, sizeof(x))
#define FILLL(x, c) memset(x, c, sizeof(x))
using namespace std;

const double EPS = 1e-8;

#define LL long long
#define pb push_back
int n, k;
int c[10], c2[10];
int c_tot, c_tot2;
void init_c() // Initalisation of Row's, in c[i]
{
    c_tot = c_tot2 = 0;
    for (int i = 1; i <= n; i += 2)
    {
        if (i == n)
        {
            c_tot++;
            c[c_tot] = i;
        }
        else
        {
            c_tot++;
            c[c_tot] = i;
            c_tot++;
            c[c_tot] = i;
        }
    }
    for (int i = 2; i <= n; i += 2)
    {
        if (i == n)
        {
            c_tot2++;
            c2[c_tot2] = i;
        }
        else
        {
            c_tot2++;
            c2[c_tot2] = i;
            c_tot2++;
            c2[c_tot2] = i;
        }
    }
}
LL R[30][30];
LL R2[30][30];
void solve()
{
    CLEAR(R);
    CLEAR(R2);
    R[0][0] = 1;
    for (int i = 1; i <= c_tot; i++)
    {
        for (int j = 0; j <= c[i]; j++)
        {
            R[i][j] = R[i - 1][j] + R[i - 1][j - 1] * (c[i] - (j - 1));
            // cout << R[i][j]<<" ";
        }
        // cout << endl;
    }
    R2[0][0] = 1;
    for (int i = 1; i <= c_tot2; i++)
    {
        for (int j = 0; j <= c2[i]; j++)
        {
            R2[i][j] = R2[i - 1][j] + R2[i - 1][j - 1] * (c2[i] - (j - 1));
        }
    }

    LL ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += R[c_tot][i] * R2[c_tot2][k - i];
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d", &n, &k);
        init_c();
        solve();
    }
    return 0;
}