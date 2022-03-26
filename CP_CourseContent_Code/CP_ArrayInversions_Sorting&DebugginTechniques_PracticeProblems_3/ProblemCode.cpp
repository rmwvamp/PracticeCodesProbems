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

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return ((a.second) * (b.first.size() - b.second)) > ((b.second) * (a.first.size() - a.second));
}

void solve()
{
    // SOLUTION STARTS
    sci(m);
    vector<string> arr(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    vector<pair<string, int>> count(m);
    for (int i = 0; i < m; i++)
    {
        count[i].first = arr[i];
        count[i].second = 0;
        for (int j = 0; j < arr[i].size(); j++)
        {
            if (arr[i][j] == '0')
            {
                count[i].second++;
            }
        }
    }
    sort(all(count), cmp);

    /* Now would concatenate m strings together by their order.
       j>i
       Now need to find out the number of inversion counts
       */
    int cnt1 = 0;
    int cnt0 = 0;
    int InversionCount = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < count[i].first.size(); j++)
        {
            /* code */
            if (count[i].first[j] == '0')
            {
                // cnt0++;
                InversionCount += cnt1;
            }
            else
            {
                cnt1++;
            }
        }
    }
    cout << InversionCount << endl;
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
