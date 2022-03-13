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

int QueensPlaced[16];
int ans, n;
inline bool check(int row, int col)
{
    for (int prevRow = 0; prevRow < row; prevRow++)
    {
        int prevcol = QueensPlaced[prevRow];
        if (prevRow == row || prevcol == col || abs(row - prevRow) == abs(col - prevcol))
        {
            return 0;
        }
        else if (abs(prevRow - row) == 2 && abs(col - prevcol) == 1)
        {
            return 0;
        }
        else if (abs(prevRow - row) == 1 && abs(col - prevcol) == 2)
        {
            return 0;
        }
    }
    return 1;
}
void rec(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (check(row, col))
        {
            QueensPlaced[row] = col;
            rec(row + 1);
            QueensPlaced[row] = -1;
        }
    }
}
void solve()
{
    // SOLUTION STARTS
    ans = 0;
    cin >> n;
    memset(QueensPlaced, -1, sizeof(QueensPlaced));
    rec(0);
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
