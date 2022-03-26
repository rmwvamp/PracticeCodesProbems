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

void Check7rec(vector<ll> &arr, int n, int i, bool &flag)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == 7)
        flag = true;
    Check7rec(arr, n, i + 1, flag);
}
void First7rec(vector<ll> &arr, int n, int i, bool &flag)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == 7 && i == 0)
        flag = true;
    First7rec(arr, n, i + 1, flag);
}
void Last7rec(vector<ll> &arr, int n, int i, bool &flag)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == 7 && i == n - 1)
        flag = true;
    Last7rec(arr, n, i + 1, flag);
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool flag = 0;
    Check7rec(arr, arr.size(), 0, flag);
    flag == 0 ? cout << "No 7" << endl : cout << "Yes 7" << endl;
    flag = 0;
    First7rec(arr, arr.size(), 0, flag);
    flag == 0 ? cout << "No First 7" << endl : cout << "Yes First 7" << endl;
    flag = 0;
    Last7rec(arr, arr.size(), 0, flag);
    flag == 0 ? cout << "No Last 7" << endl : cout << "Yes Last 7" << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
