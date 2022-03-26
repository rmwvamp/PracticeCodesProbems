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
int n;
vector<int> LastQueenPlacedPosition;
int ans = 0;

void NQueens_RecursiveCall(int row)
{
    if (row == n)
    {
        ans++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        bool safe = 1;
        for (int PreviousRow = 0; PreviousRow < row; PreviousRow++)
        {
            int PreviousColumnPosition = LastQueenPlacedPosition[PreviousRow];
            if (PreviousColumnPosition == col || abs(col - PreviousColumnPosition) == abs(row - PreviousRow))
            {
                safe = 0;
            }
        }

        if (safe)
        {
            LastQueenPlacedPosition.pb(col);
            NQueens_RecursiveCall(row + 1);
            LastQueenPlacedPosition.pop_back();
        }
    }
}

void solve()
{
    // SOLUTION STARTS
    cin >> n;
    NQueens_RecursiveCall(0);
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
