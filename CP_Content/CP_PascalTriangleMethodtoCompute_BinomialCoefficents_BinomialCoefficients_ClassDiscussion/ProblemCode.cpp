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

vector<vector<ll>> PascalTriangle(1001, vector<ll>(1001, -1));

void PreComputing_PascalTriangleValues()
{
    PascalTriangle[0][0] = 1;
    for (int row = 1; row <= 1000; row++)
    {
        PascalTriangle[row][0] = 1;
        for (int col = 1; col < row; col++)
        {
            PascalTriangle[row][col] = (PascalTriangle[row - 1][col] % mod + PascalTriangle[row - 1][col - 1] % mod) % mod;
        }
        PascalTriangle[row][row] = 1;
    }
}

void solve()
{
    // SOLUTION STARTS
    PreComputing_PascalTriangleValues();
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //     {
    //         cout << PascalTriangle[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    scii(n, r);
    cout << PascalTriangle[n][r] << endl;
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
