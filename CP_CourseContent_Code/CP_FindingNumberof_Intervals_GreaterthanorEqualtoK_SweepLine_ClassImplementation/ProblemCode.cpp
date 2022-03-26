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
    vector<pair<ll, ll>> event;
    for (int i = 0; i < n; i++)
    {
        ll l, r;
        cin >> l >> r;
        event.pb({l, 1});
        event.pb({r, -1});
    }
    sort(event.begin(), event.end());
    int cnt = 0;
    int LenCovered[n + 1];
    memset(LenCovered, 0, sizeof(LenCovered));
    for (int i = 0; i < event.size(); i++)
    {
        int j = i;
        while (j < event.size() && event[j].first == event[i].first)
        {
            cnt += event[j].second;
            j++;
        }
        i = j - 1;
        if (i != (event.size() - 1))
        {

            ll SegmentLength = event[i + 1].first - event[i].first;
            LenCovered[cnt] += SegmentLength;
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        LenCovered[i] += LenCovered[i + 1];
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
