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

struct bag
{
    int sumVal;
    map<int, int> mp;
    bag()
    {
        sumVal = 0;
        mp.clear();
    }
    void insert(int x)
    {
        mp[x]++;
        sumVal += x;
    }

    void remove(int x)
    {
        if (mp.find(x) == mp.end())
            return;
        mp[x]--;
        if (mp[x] == 0)
        {
            mp.erase(x);
        }
        sumVal -= x;
    }
}

bool cmp(vector<int> v1, vector<int> v2)
{
    int num = v1[1];
    int num2 = v1[1];
    return num < num2;
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(2, 0);
        cin >> temp[0]; // efficiency
        cin >> temp[1]; // speed
        arr.pb(temp);
    }
    sort(all(arr), cmp);
    for (int i = n - 1; i > 0; i++)
    {
        /* code */
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
