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

bool cmp(vector<int> v1, vector<int> v2)
{
    int num = v1[1];
    int num2 = v2[1];
    return num < num2;
}

void solve()
{
    // SOLUTION STARTS
    scii(n, k);
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        // vector<int> temp(2);

        cin >> arr[i][0]; // efficiency
        cin >> arr[i][1]; // speed
        // arr.pb(temp);
    }

    sort(all(arr), cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    priority_queue<int> pq;
    int metric = 0;
    int MinSpeedofTeam = 0;
    int SumofEfficiency = 0;
    int MaxMetric = 0;

    for (int i = n - 1; i >= n - k; i--)
    {
        pq.push(-arr[i][0]);
        SumofEfficiency += arr[i][0];
    }
    MaxMetric = SumofEfficiency * arr[n - k][1];

    for (int i = n - k - 1; i >= 0; i--)
    {
        SumofEfficiency += pq.top();
        pq.pop();
        SumofEfficiency += arr[i][0];
        pq.push(-arr[i][0]);
        MinSpeedofTeam = arr[i][1];
        metric = MinSpeedofTeam * SumofEfficiency;
        if (metric > MaxMetric)
        {
            MaxMetric = metric;
        }
    }
    cout << MaxMetric << endl;
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
