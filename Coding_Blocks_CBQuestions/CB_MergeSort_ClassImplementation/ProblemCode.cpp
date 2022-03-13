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

void Merge_TwoSortedArrays(int *a, int *b, int *c, int Start, int End)
{

    int mid = (Start + End) / 2;
    int i = Start;
    int j = mid + 1;
    int k = Start;
    while (i <= mid && j <= End)
    {
        if (b[i] <= c[j])
        {
            a[k++] = b[i++];
        }
        else
        {
            a[k++] = c[j++];
        }
    }
    while (i <= mid)
    {
        a[k++] = b[i++];
    }
    while (j <= End)
    {
        a[k++] = c[j++];
    }
}
void MergeSort(int *a, int Start, int End)
{
    // Base case
    if (Start >= End)
    {
        return;
    }

    // Recursive case
    // 1. Dividing the array
    int b[100], c[100];
    int mid = (Start + End) / 2;
    for (int i = 0; i <= mid; i++)
    {
        b[i] = a[i];
    }
    for (int i = mid + 1; i <= End; i++)
    {
        c[i] = a[i];
    }

    // 2. Sorting the Individual Arrays
    MergeSort(b, Start, mid);
    MergeSort(c, mid + 1, End);

    // 3. Merging the individual Sorted Arrays
    Merge_TwoSortedArrays(a, b, c, Start, End);
}
void solve()
{
    // SOLUTION STARTS
    int a[] = {8, 11, 2, 4, 6, 1, 4, 5};
    int la = sizeof(a) / sizeof(int);
    cout << la << endl;
    for (int i = 0; i < la; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    MergeSort(a, 0, la - 1);
    for (int i = 0; i < la; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
