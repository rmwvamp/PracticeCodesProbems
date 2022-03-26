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

int allowed[10][10];
int QueensPlaced[10];
int ans;

inline bool check(int row, int col)
{
    // int PreviousQueenRow = row > 1 ? row - 1 : 0;

    for (int pRow = 0; pRow < row; pRow++)
    {
        if (allowed[row][col] == -1)
        {
            return 0;
        }
        int pCol = QueensPlaced[pRow];
        if (pCol == col || abs(pRow - row) == abs(pCol - col))
        {
            return 0;
        }
    }

    return 1;
}

void rec(int row)
{
    if (row == 8)
    {
        ans++;
        // cout << ans << endl;
        return;
    }
    for (int col = 0; col < 8; col++)
    {
        /* code */
        // int PreviousQueenRow = row > 1 ? row - 1 : 0;
        // int PreviousQueenCol = QueensPlaced[PreviousQueenRow];
        if (check(row, col))
        {
            QueensPlaced[row] = col;

            rec(row + 1);
            // QueensPlaced[row] = 0;
        }
    }
    // return ans;
}
void solve()
{
    ans = 0; // 0 is allowed and -1 is not allowed
    memset(allowed, 0, sizeof(allowed));
    // SOLUTION STARTS
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                allowed[i][j] = -1;
            }
        }
    }
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout << allowed[i][j];
    //     }
    //     cout << endl;
    // }
    rec(0);

    // QueensPlaced[0] = 0;
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
