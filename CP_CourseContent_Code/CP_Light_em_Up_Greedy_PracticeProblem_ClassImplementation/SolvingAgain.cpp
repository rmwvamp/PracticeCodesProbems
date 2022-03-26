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

void solve()
{
    // SOLUTION STARTS
    scii(n, k);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int NumberofOperations = 0;
    vector<ll> PartialSum(n, 0);
    vector<ll> PrefixSum(n, 0);
    for (int i = 0; i <= n - k; i++)
    {
        // Create the Prefix Sum
        if (i)
        {
            PrefixSum[i] = PartialSum[i] + PrefixSum[i - 1];
        }
        else
        {
            PrefixSum[i] = arr[i];
        }
        if ((PrefixSum[i] + arr[i]) % 2 == 0) // A flip needs to be done, needs to turn all the bulbs on
        {
            NumberofOperations++;
            PartialSum[i + 1] += 1;
            PartialSum[i + k] -= 1;
        }
    }

    cout << NumberofOperations << endl;
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
