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

ll PrintNumbers_IncreasingOrder(auto *arr, int n)
{
    if (n == 2)
    {
        if (arr[0] > arr[1])
        {
            swap(arr[0], arr[1]);
            cout << arr[0] << " " << arr[1] << " ";
            return arr[0];
        }
    }
    if (arr[0] <= PrintNumbers_IncreasingOrder(arr + 1, n - 1))
    {
        cout << arr[0] << " ";
    }
    else
    {
    }
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    // vector<ll> arr(n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    PrintNumbers_IncreasingOrder(arr, n);
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
