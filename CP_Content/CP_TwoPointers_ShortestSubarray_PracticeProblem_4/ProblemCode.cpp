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

void remove(int num, vector<int> &frequency, int &CountofDistinctIntegers)
{
    frequency[num]--;
    if (frequency[num] == 0)
    {
        CountofDistinctIntegers--;
    }
}

void insert(int num, vector<int> &frequency, int &CountofDistinctIntegers)
{
    frequency[num]++;
    if (frequency[num] == 1)
    {
        CountofDistinctIntegers++;
    }
}

// int InsertionCheck(int num, vector<int> frequency, int CountofDistinctIntegers)
// {
//     frequency[num]++;
//     if (frequency[num] == 1)
//     {
//         CountofDistinctIntegers++;
//     }
//     return CountofDistinctIntegers;
// }

void solve()
{
    // SOLUTION STARTS

    /*Basic Input and Two Pointers Solution */
    sci(n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int tail = 0;
    int head = -1;
    int ans = 1e9;
    int CountofDistinctIntegers = 0;
    int CountofDistinctIntegersCompleteArray = 0;
    vector<int> frequency(1e7);
    vector<int> FrequencyforEntireArray(1e7);
    for (int i = 0; i < n; i++)
    {
        insert(arr[i], FrequencyforEntireArray, CountofDistinctIntegersCompleteArray);
    }

    while (tail < n)
    {
        while (head + 1 < n && CountofDistinctIntegers < CountofDistinctIntegersCompleteArray)
        {
            head++;
            insert(arr[head], frequency, CountofDistinctIntegers);
        }
        if (head >= tail)
        {
            if (CountofDistinctIntegers == CountofDistinctIntegersCompleteArray)
            {
                ans = min(ans, head - tail + 1);
            }
            remove(arr[tail], frequency, CountofDistinctIntegers);

            tail++;
        }

        else
        {
            remove(arr[tail], frequency, CountofDistinctIntegers);

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
