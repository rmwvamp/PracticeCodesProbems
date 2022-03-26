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

void insert(int &num, vector<int> &frequency, ll &CountofDistinctIntegers)
{
    frequency[num]++;
    if (frequency[num] == 1)
    {
        CountofDistinctIntegers++;
    }
}

void remove(int &num, vector<int> &frequency, ll &CountofDistinctIntegers)
{
    frequency[num]--;
    if (frequency[num] == 0)
    {
        CountofDistinctIntegers--;
    }
}
void solve()
{
    // SOLUTION STARTS
    scii(n, d);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tail = 0;
    int head = -1;
    ll ans = 1e18;
    vector<int> frequency(1e7);
    ll CountofDistinctIntegers = 0;

    while (tail < n)
    {
        while (head + 1 < n && ((head + 1) - tail + 1 <= d))
        {
            head++;
            insert(arr[head], frequency, CountofDistinctIntegers);
        }
        if (head >= tail)
        {
            if (head - tail + 1 == d)
                ans = min(ans, CountofDistinctIntegers);
            remove(arr[tail], frequency, CountofDistinctIntegers);
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << ans << endl;
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
