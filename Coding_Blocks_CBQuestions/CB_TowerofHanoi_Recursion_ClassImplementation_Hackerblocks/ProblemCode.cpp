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
// ll count;
ll cnt;
void TowerofHanoi(int n, string source, string helper, string destination)
{
    if (n == 0)
        return;

    TowerofHanoi(n - 1, source, destination, helper);
    cnt++;
    cout << "Move " << n << "th disc from " << source << " to " << destination << endl;
    TowerofHanoi(n - 1, helper, source, destination);
}
void solve()
{
    // SOLUTION STARTS
    // char set[] = {'A', 'B', 'C'};
    // int n = sizeof(set) / sizeof(char);
    sci(n);
    cnt = 0;
    TowerofHanoi(n, "T1", "T3", "T2");
    cout << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
