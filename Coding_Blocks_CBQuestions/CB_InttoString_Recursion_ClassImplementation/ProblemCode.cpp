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

vector<string> NumstoCharacter = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
void Int_To_String(int num, int n, int i)
{
    if (i == n)
    {
        return;
    }
    int rem = num % 10;
    Int_To_String(num / 10, n, i + 1);
    cout << NumstoCharacter[rem] << " ";
    if (i == 0)
        cout << endl;
}

void Int_To_String_BetterSolution(int num)
{
    if (num == 0)
    {
        return;
    }
    int rem = num % 10;
    Int_To_String_BetterSolution(num / 10);
    cout << NumstoCharacter[rem] << " ";
}

void solve()
{
    // SOLUTION STARTS
    sci(x);
    // Int_To_String(num, n, 0);
    Int_To_String_BetterSolution(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
