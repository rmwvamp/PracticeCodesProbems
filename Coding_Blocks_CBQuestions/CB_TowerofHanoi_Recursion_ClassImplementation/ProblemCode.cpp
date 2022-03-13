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

void TowerofHanoi(char Source, char Helper, char Destination, int n)
{
    // Base case
    if (n == 0) // if no dis
    {
        return;
    }

    // Entire WorkFlow using Recursion
    // 1. First Moving n-1 disks from helper to destination
    TowerofHanoi(Source, Destination, Helper, n - 1);
    // then moving the nth disk from source to Destination
    cout << "Taking " << n << " disk from " << Source << " to " << Destination << endl;

    // Then moving my n-1 disks from helper to the actual Destination
    TowerofHanoi(Helper, Source, Destination, n - 1);
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    TowerofHanoi('A', 'B', 'C', n);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
