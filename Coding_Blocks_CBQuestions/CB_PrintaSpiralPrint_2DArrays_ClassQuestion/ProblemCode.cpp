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

void solve()
{
    // SOLUTION STARTS
    sci(n);
    int arr[n][n];
    int number = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = number;
            number++;
        }
    }

    /* Logic Code for the Spiral Print */
    int StartingColumnn = 0;
    int StartingRow = 0;

    int EndingColumn = n - 1;
    int EndingRow = n - 1;

    while (StartingColumnn <= EndingColumn && StartingRow <= EndingRow)
    {
        for (int col = StartingColumnn; col <= EndingColumn; col++)
        {
            cout << arr[StartingRow][col] << " ";
        }
        StartingRow++;

        for (int row = StartingRow; row <= EndingRow; row++)
        {
            cout << arr[row][EndingColumn] << " ";
        }
        EndingColumn--;
        for (int col = EndingColumn; col >= StartingColumnn; col--)
        {
            cout << arr[EndingRow][col] << " ";
        }
        EndingRow--;
        for (int row = EndingRow; row >= StartingRow; row--)
        {
            /* code */
            cout << arr[row][StartingColumnn] << " ";
        }
        StartingColumnn++;
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin >> t;while (t--)
    solve();

    return 0;
}
