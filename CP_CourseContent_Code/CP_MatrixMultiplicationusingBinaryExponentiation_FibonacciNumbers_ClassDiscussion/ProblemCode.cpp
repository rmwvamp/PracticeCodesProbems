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

vector<vector<ll>> MatrixMultiplication(vector<vector<ll>> a, vector<vector<ll>> b)
{
    vector<vector<ll>> ResultantMatrix(a.size(), vector<ll>(a.size(), 0));

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b.size(); k++)
            {
                ResultantMatrix[i][j] = ResultantMatrix[i][j] % mod + ((a[i][k] % mod) * (b[k][j] % mod) % mod) % mod;
            }
        }
    }
    return ResultantMatrix;
}
ll Calculating_FibonacciNumbers_using_MatrixMultiplication_BinaryExponentiation(ll a)
{

    vector<vector<ll>> ans = {{1, 0},
                              {0, 1}};
    vector<vector<ll>> EquationMatrix = {{1, 1},
                                         {1, 0}};

    while (a)
    {
        if (a % 2)
        {
            ans = MatrixMultiplication(ans, EquationMatrix);
        }

        EquationMatrix = MatrixMultiplication(EquationMatrix, EquationMatrix);
        a /= 2;
    }

    return ans[0][1];
}

void solve()
{
    // SOLUTION STARTS
    sci(n);

    cout << Calculating_FibonacciNumbers_using_MatrixMultiplication_BinaryExponentiation(n) << endl;
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
