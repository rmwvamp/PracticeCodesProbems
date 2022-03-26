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

ll Median_of_an_Vector(vector<ll> arr)
{
    int n = arr.size();
    if (n % 2)
    {
        return arr[n / 2];
    }
    else
    {
        return arr[n / 2] + arr[n / 2 + 1] / 2;
    }
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<ll> RowPositions;
    vector<ll> ColumnPositions;
    for (int i = 0; i < n; i++)
    {
        scii(x, y);
        RowPositions.push_back(x);
        ColumnPositions.push_back(y);
    }
    sort(all(RowPositions));
    sort(all(ColumnPositions));

    ll X_MeetingPoint = Median_of_an_Vector(RowPositions);
    ll Y_MeetingPoint = Median_of_an_Vector(ColumnPositions);
    ll cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += abs(RowPositions[i] - X_MeetingPoint);
        cost += abs(ColumnPositions[i] - Y_MeetingPoint);
    }
    cout << cost << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;while (t--)
    solve();

    return 0;
}
