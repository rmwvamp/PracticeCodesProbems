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

void PrintIncreasing_usingRecursion(int n, int i)
{
    if (i == n + 1)
    {
        cout << endl;
        return;
    }
    cout << i << " ";
    PrintIncreasing_usingRecursion(n, i + 1);
}
void PrintDecreasing_usingRecursion(int n, int i)
{
    if (i == n + 1)
    {
        return;
    }
    // cout << endl;
    PrintDecreasing_usingRecursion(n, i + 1);
    cout << i << " ";
}

void solve()
{
    scii(n, m);
    PrintIncreasing_usingRecursion(n, 1);
    PrintDecreasing_usingRecursion(m, 1);
    // SOLUTION STARTS
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
