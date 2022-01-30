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

void insert(char num, vector<int> &frequency, ll &CountofDistinctChar)
{
    int CharIntegerConvert = num;
    frequency[CharIntegerConvert]++;
    if (frequency[CharIntegerConvert] == 1)
    {
        CountofDistinctChar++;
    }
}

void remove(char num, vector<int> &frequency, ll &CountofDistinctChar)
{
    int CharIntegerConvert = num;
    frequency[CharIntegerConvert]--;
    if (frequency[CharIntegerConvert] == 0)
    {
        CountofDistinctChar--;
    }
}

// bool InsertionCheck(char num, vector<int> &frequency, ll &CountofDistinctChar)
// {
//     frequency[num]++;
//     if (frequency[num] == 1)
//     {
//         CountofDistinctChar++;
//     }
// }

void solve()
{
    // SOLUTION STARTS
    sci(n);
    char s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    ll ans = 0;

    /*Removing Contribution */
    // vector<int> CountofSubArrayswithNoContribution(125); // 97-123
    for (int i = 97; i < 123; i++)
    {
        vector<int> frequency(125);
        ll CountofDistinctChar = 0; //
        int tail = 0;
        int head = -1;
        while (tail < n)
        {
            while (head + 1 < n)
            {
                head++;
                if (head)
                    insert(s[head], frequency, CountofDistinctChar);
            }
            ans += CountofDistinctChar;
            if (head >= tail)
            {
                remove(s[tail], frequency, CountofDistinctChar);
                tail++;
            }
            else
            {
                remove(s[tail], frequency, CountofDistinctChar);

                tail++;
                head = tail - 1;
            }
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
