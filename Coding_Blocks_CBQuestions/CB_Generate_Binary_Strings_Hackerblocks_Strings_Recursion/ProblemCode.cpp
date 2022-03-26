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

void rec(string &str, int n, int i)
{
    if (i == n)
    {
        // cout << "check 1" << endl;
        cout << str << " ";
        return;
    }
    if (str[i] = '?')
    {
        // cout << "check 3" << endl;
        str[i] = '0';
        rec(str, n, i + 1);
        // cout << str << " ";
        str[i] = '1';
        // cout << 1;
    }
    rec(str, n, i + 1);

    // cout << "check 4" << endl;
}

void rec_secondtry(string &input, char *output, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << " ";
        return;
    }
    if (input[i] == '?')
    {
        output[j] = '0';
        rec_secondtry(input, output, i + 1, j + 1);
        output[j] = '1';
        rec_secondtry(input, output, i + 1, j + 1);
    }
    else
    {
        output[j] = input[i];
        rec_secondtry(input, output, i + 1, j + 1);
    }
}
void solve()
{
    // SOLUTION STARTS
    scs(str);
    // char input[] = str;
    char output[100];
    rec_secondtry(str, output, 0, 0);
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
