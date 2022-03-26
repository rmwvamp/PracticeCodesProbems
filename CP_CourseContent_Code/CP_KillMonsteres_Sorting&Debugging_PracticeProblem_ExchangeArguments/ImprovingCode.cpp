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

bool cmp(vector<int> v1, vector<int> v2)
{
    return v2[0] - v2[1] < v1[0] - v1[1];
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        scii(a, b);
        arr[i][0] = a;
        arr[i][1] = b;
    }
    sort(all(arr), cmp);
    ll Answer_RequiredSoldiers = arr[0][0];
    ll SoldiersOnFieldAfterDefeatingIthMonster = arr[0][0] - arr[0][1];
    for (int i = 1; i < n; i++)
    {
        ll SoldierRequiredforIthMonster = max(0LL, arr[i][0] - SoldiersOnFieldAfterDefeatingIthMonster);
        Answer_RequiredSoldiers += SoldierRequiredforIthMonster;
        SoldiersOnFieldAfterDefeatingIthMonster += SoldierRequiredforIthMonster - arr[i][1];
    }
    cout << Answer_RequiredSoldiers << endl;
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
