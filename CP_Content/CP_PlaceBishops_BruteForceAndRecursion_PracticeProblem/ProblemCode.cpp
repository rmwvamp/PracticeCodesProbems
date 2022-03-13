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
int ans;
int BishopsPlaced[10][10];
inline bool check(int row, int col)
{
    // for (auto &x : BishopsPlaced)
    // {
    //     if (abs(PrevRow - row) == abs(PrevCol - col))
    //     {
    //         return 0;
    //     }
    // }
    for (int PrevRow = 0; PrevRow < row; PrevRow++)
    {
        for (int PrevCol = 0; PrevCol < col; PrevCol++)
        {
            if (BishopsPlaced[PrevRow][PrevCol] == 1)
            {
                if (abs(PrevRow - row) == abs(PrevCol - col))
                {
                    return 0;
                }
            }
        }
    }
    return 1;
}
void rec(int row, int col)
{
    if (row == n || col == n)
    {
        if (col == n)
        {
            ans++;
            rec(row + 1, 0);
        }
        return;
    }

    for (int ColIteration = col; ColIteration < n; ColIteration++)
    {
        if (check(row, ColIteration))
        {
            BishopsPlaced[row][ColIteration] = 1;
            rec(row, ColIteration + 1);
            BishopsPlaced[row][ColIteration] = -1;
        }
    }
}
void solve()
{
    // SOLUTION STARTS
    cin >> n >> k;
    memset(BishopsPlaced, -1, sizeof(BishopsPlaced));
    ans = 0;
    rec(0, 0);
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
