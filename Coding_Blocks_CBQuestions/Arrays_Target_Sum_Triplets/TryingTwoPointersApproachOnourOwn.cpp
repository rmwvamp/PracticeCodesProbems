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

#define PRINT(a, n)   \
    do                \
    {                 \
        int i;        \
    for (i = 0; ?; ?) \
        {             \
            ?         \
        }             \
    } while (0)

void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(all(arr));
    sci(t);
    // vector<pair<pair<int, int>, int>> ans;

    /* Creating a Vector of Vector */
    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++)
    {
        // map<int, int> temp;
        vector<int> temp;
        int RequiredSum = t - arr[i];
        int start = i + 1;
        int end = n - 1;
        while (start < end)
        {
            int PairSum = arr[start] + arr[end];
            if (PairSum == RequiredSum)
            {
                // ans.pb({{arr[i], arr[start]}, arr[end]});
                temp.push_back(arr[i]);
                temp.push_back(arr[start]);
                temp.push_back(arr[end]);
                // temp[arr[i]]++;
                // temp[arr[start]]++;
                // temp[arr[end]]++;

                start++;
                end--;
            }
            else if (PairSum > RequiredSum)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        ans.push_back(temp);
    }
    cout << ans.size() << endl;

    /* My vector  of vector has the answers in my answer vector */
    for (int i = 0; i < ans.size(); i++)
    {
        int j = 0;

        cout << ans[i][j] << ", " << ans[i][j + 1] << " and " << ans[i][j + 2] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
