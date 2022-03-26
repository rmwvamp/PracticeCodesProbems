#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
// #define pb push_back
#define fi first
#define se second
// #define pb push_back
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

int s, ra, pa, rb, pb, c;
int AllowedPositions[10][10]; // 1-> not allowed, obstruction
                              // 0-> Allowed

inline bool check(int x, int y)
{
    if (x >= 1 && y >= 1 && x <= s && y <= (2 * x - 1) && AllowedPositions[x][y] == 0)
    {
        return true;
    }
}

int GetBestScore(int a, int b, int x, int y)
{
    vector<pair<int, int>> move1, move2;
    if (check(a, b - 1))
    {
        move1.emplace_back(make_pair(a, b - 1));
    }
    if (check(a, b + 1))
    {
        move1.emplace_back(make_pair(a, b + 1));
    }
    if (b % 2 == 0)
    {
        if (check(a - 1, b - 1))
        {
            move1.emplace_back(make_pair(a - 1, b - 1));
        }
    }
    else
    {
        if (check(a + 1, b + 1))
        {
            move1.emplace_back(make_pair(a + 1, b + 1));
        }
    }
    // Making Moves for Bertha 2nd one
    if (check(x, y - 1))
    {
        move2.emplace_back(make_pair(x, y - 1));
    }
    if (check(x, y + 1))
    {
        move2.emplace_back(make_pair(x, y + 1));
    }
    if (y % 2 == 0)
    {
        if (check(x - 1, y - 1))
        {
            move2.emplace_back(make_pair(x - 1, y - 1));
        }
    }
    else
    {
        if (check(x + 1, y + 1))
        {
            move2.emplace_back(make_pair(x + 1, y + 1));
        }
    }

    // Base case
    if (move1.empty() && move2.empty())
    {
        return 0;
    }
    else if (!move1.empty()) // If it's not a base case, Making an Recursion Call
    {
        int best = -1000;
        for (auto &v : move1)
        {
            AllowedPositions[v.first][v.second] = 1;
            best = max(best, 1 - GetBestScore(x, y, v.first, v.second));
            AllowedPositions[v.first][v.second] = 0;
        }
        return best;
    }
    else
    {
        return -GetBestScore(x, y, a, b);
    }
}

void solve()
{
    cin >> s >> ra >> pa >> rb >> pb >> c;
    memset(AllowedPositions, 0, sizeof(AllowedPositions));
    AllowedPositions[ra][pa] = 1;
    AllowedPositions[rb][pb] = 1;
    for (int i = 0; i < c; i++)
    {
        scii(x1, y1);
        AllowedPositions[x1][y1] = 1;
    }

    cout << GetBestScore(ra, pa, rb, pb) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int cc = 1;
    cin >> t;
    while (t--)
    {
        goog(cc);
        solve();
    }

    return 0;
}
