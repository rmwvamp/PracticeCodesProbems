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

void BubbleSort_rec(vector<ll> &arr, int i, int j)
{

    if (i == arr.size() - 1 || j == arr.size())
    {
        return;
    }

    if (arr[i + 1] < arr[i])
    {
        swap(arr[i], arr[i + 1]);
        BubbleSort_rec(arr, i, j + 1);
        BubbleSort_rec(arr, i + 1, j + 1);
    }
    else
    {
        BubbleSort_rec(arr, i + 1, i + 1);
    }
}

void BubbleSort_usingRecursion_Solution(vector<ll> &arr, int n, int i)
{
    if (n == 0)
    {
        return;
    }
    if (i == n - 1)
    {
        BubbleSort_usingRecursion_Solution(arr, n - 1, 0);
        return;
    }
    if (arr[i] > arr[i + 1])
    {
        swap(arr[i], arr[i + 1]);
    }
    BubbleSort_usingRecursion_Solution(arr, n, i + 1);
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
    BubbleSort_usingRecursion_Solution(arr, arr.size(), 0);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}

void BubbleSort(int *a, int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // recursive case
    for (int i = 0; i <= n - 2; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(a[i], a[i + 1]);
        }
    }

    BubbleSort(a, n - 1);
}
void BubbleSort(int *a, int n, int i)
{
    // base case
    if (n == 0)
    {
        return;
    }
    // recursive case
    if (i == n - 1)
    {
        i = 0;
        BubbleSort(a, n - 1, i);
        return;
    }
    if (a[i] > a[i + 1])
    {
        swap(a[i], a[i + 1]);
    }
    BubbleSort(a, n, i + 1);
}