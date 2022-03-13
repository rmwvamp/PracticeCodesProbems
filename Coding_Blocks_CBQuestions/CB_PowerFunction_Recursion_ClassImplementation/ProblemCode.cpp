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

int PowerFunction_usingRecursion(int base, int power)
{
    if (power == 0)
        return 1;

    int answer = 1;
    answer = base * PowerFunction_usingRecursion(base, power - 1);
    return answer;
}

int PowerFunction_usingRecursion_BetterImplemented(int base, int power)
{
    if (power == 0)
        return 1;

    return base * PowerFunction_usingRecursion_BetterImplemented(base, power - 1);
}

void solve()
{
    // SOLUTION STARTS
    scii(base, power);
    cout << PowerFunction_usingRecursion(base, power) << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
