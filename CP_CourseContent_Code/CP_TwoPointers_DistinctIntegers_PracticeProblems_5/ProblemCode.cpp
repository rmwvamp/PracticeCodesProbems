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

void insert(int &x, vector<int> &FrequencyofElements, int &DistinctElementsCount)
{
    FrequencyofElements[x]++;
    if (FrequencyofElements[x] == 1)
    {
        DistinctElementsCount++;
    }
}
void remove(int &x, vector<int> &FrequencyofElements, int &DistinctElementsCount)
{
    FrequencyofElements[x]--;
    if (FrequencyofElements[x] == 0)
    {
        DistinctElementsCount--;
    }
}
void solve()
{
    // SOLUTION STARTS
    // SOLUTION STARTS
    scii(n, k);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /* Maintaining a Frequency Count in O(1)*/
    int DistinctElementsCount = 0;
    vector<int> FrequencyofElements(1000000);

    /* Two Pointers Code Starts*/
    int tail = 0;
    int head = -1;
    int ans = 0;
    while (tail < n)
    {
        while (head + 1 < n && ((DistinctElementsCount < k && FrequencyofElements[arr[head + 1]] == 0) || (DistinctElementsCount <= k && FrequencyofElements[arr[head + 1]] > 0)))
        {
            head++;
            insert(arr[head], FrequencyofElements, DistinctElementsCount);
        }
        if (DistinctElementsCount == k)
        {
            ans++;
        }
        if (head >= tail)
        {
            remove(arr[tail], FrequencyofElements, DistinctElementsCount);
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
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
