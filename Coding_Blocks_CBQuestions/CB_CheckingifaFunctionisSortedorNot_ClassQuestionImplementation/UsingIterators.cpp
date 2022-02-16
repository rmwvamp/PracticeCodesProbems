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

bool ArraySortedorNot(int *a, int n, int i)
{
    if (i == n - 1)
        return true;
    if (a[i] <= a[i + 1] && ArraySortedorNot(a, n, i + 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ArraySortedorNot(auto *a, int n)
{
    if (n == 1)
    {
        return true;
    }
    if (a[0] <= a[1] && ArraySortedorNot(a + 1, n - 1))
    {
        return true;
    }
    else
    {
        return false;
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
    if (ArraySortedorNot(arr, n))
    {
        cout << "Sorted" << endl;
    }
    else
    {
        cout << "Not Sorted" << endl;
    }
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
