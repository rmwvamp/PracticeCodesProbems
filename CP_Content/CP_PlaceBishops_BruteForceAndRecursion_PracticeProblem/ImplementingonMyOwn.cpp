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

int n, k;
// C[i] represents the number of cells in that row.. and we'll make two c[i]..
// one for black and one for white cells
int c[10], c2[10];
int c_tot, c_tot2;
ll R[30][30]; // R[i][j] represents the number of solutions for placing j pieces in the first i rows.
ll R2[30][30];

void InitalisationofCArray()
{
    c_tot = c_tot2 = 0;
    for (int i = 1; i <= n; i += 2) //
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
    for (int i = 2; i <= n; i += 2) // whites, i'll be starting from 2
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
void solve()
{
    cin >> n >> k;
    InitalisationofCArray();
    memset(R, 0, sizeof(R));
    memset(R, 0, sizeof(R2));
    R[0][0] = 1;
    for (int i = 1; i <= c_tot; i++) // looping on black rows
    {
        for (int j = 0; j <= c[i]; j++) // placing 0 pieces, placing 1 pieces... maximum number of columns present in the row i.e. c[i]
        {
            R[i][j] = R[i - 1][j] + R[i - 1][j - 1] * (c[i] - (j - 1));
        }
    }
    R2[0][0] = 1;
    for (int i = 1; i <= c_tot2; i++) // looping on white    rows
    {
        for (int j = 0; j <= c2[i]; j++) // placing 0 pieces, placing 1 pieces... maximum number of columns present in the row i.e. c[i]
        {
            R2[i][j] = R2[i - 1][j] + R2[i - 1][j - 1] * (c2[i] - (j - 1));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++)
    {
        ans += R[c_tot][i] * R2[c_tot2][k - i];
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
        solve();

    return 0;
}
