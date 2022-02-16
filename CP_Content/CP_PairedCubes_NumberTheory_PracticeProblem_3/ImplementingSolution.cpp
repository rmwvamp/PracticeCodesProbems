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
    sci(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> m;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        int number = arr[i];
        int OnePowerRemaining = 1;
        int TwoPowerRemaining = 1;
        for (int j = 2; j * j <= number; j++) // Prime Factorizing a Number
        {
            int cnt = 0;
            while (number % j == 0)
            {
                cnt++;
                number /= j;
            }
            cnt %= 3;
            for (int k = 0; k < cnt; k++)
            {
                OnePowerRemaining *= j;
            }
            if (cnt)
            {
                for (int k = 0; k < 3 - cnt; k++)
                {
                    TwoPowerRemaining *= j;
                }
            }
        }
        if (number > 1)
        {
            OnePowerRemaining *= number;
            TwoPowerRemaining *= number * number;
        }
        ans += m[TwoPowerRemaining];
        m[OnePowerRemaining]++;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
