#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pb push_back

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

ll mod;
vector<ll> SubsetSumModulo(vector<ll> arr)
{
    vector<ll> temp;
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (mask & (1 << j))
            {
                sum = (sum % mod + arr[j] % mod) % mod;
            }
        }
        temp.pb(sum % mod);
    }
    return temp;
}

void solve()
{

    // SOLUTION STARTS
    sci(n);
    cin >> mod;
    vector<ll> SubsetA;
    vector<ll> SubsetB;

    for (int i = 0; i < n; i++)
    {
        sci(x);
        if (i % 2)
        {
            SubsetA.pb(x);
        }
        else
        {

            SubsetB.pb(x);
        }
    }
    vector<ll> SubsetSumA = SubsetSumModulo(SubsetA);
    vector<ll> SubsetSumB = SubsetSumModulo(SubsetB);
    vector<ll> Solution;
    ll MaxSum = LONG_MIN;
    sort(all(SubsetSumA));
    sort(all(SubsetSumB));
    for (int i = 0; i < SubsetSumA.size(); i++)
    {
        /* code */
        int pt = (upper_bound(all(SubsetSumB), mod - SubsetA[i]) - SubsetSumB.begin()) - 1;
        // int pt = lower_bound(all(SubsetSumB), mod - SubsetA[i]) - SubsetSumB.begin();
        // pt--;

        MaxSum = max((SubsetSumA[i] % mod + SubsetSumB[pt] % mod) % mod, MaxSum);
    }
    cout << MaxSum << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
