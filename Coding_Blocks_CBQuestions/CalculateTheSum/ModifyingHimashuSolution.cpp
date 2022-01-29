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
    sci(n);
    vector<int> arr(2 * n, 0);

    for (int i = n; i < (2 * n); i++)
    {

        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        /* code */
        arr[i] = arr[i + n];
    }

    sci(q);
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    while (q--)
    {

        ans += sum * (q + 1);
    }
    cout << ans << endl;
}
int main()
{
    int n = 5, k;
    vector<int> test = {0, 9, 2, 1, 4, 3};
    // while(1){
    k = 1 + (rand() % n);
    random_shuffle(test.begin() + 1, test.end());
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
