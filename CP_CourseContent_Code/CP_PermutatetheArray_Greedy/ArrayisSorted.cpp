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

// bool cmp(pair<ll, ll> m1, pair<ll, ll> m2)
// {
//     return m1.second > m2.second;
// }

void ReversetheArray(auto &arr, int start, int end)
{
    int mid = (end - start + 1) / 2;
    for (int i = start; i < start + mid; i++)
    {
        swap(arr[i], arr[end - i + start]);
    }
}

void RotatetheVector(auto &arr, int no_of_rotations)
{
    ReversetheArray(arr, arr.size() - no_of_rotations, arr.size() - 1);
    ReversetheArray(arr, 0, arr.size() - no_of_rotations - 1);
    ReversetheArray(arr, 0, arr.size() - 1);
}
void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<ll> arr(n);
    map<ll, ll> mt;
    int max_occurrence_index = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mt[arr[i]]++;
    }
    // Array is sorted 1 2 2 2 3 3
    // count the number of occurrences with maximum sum
    for (auto x : mt)
    {
        if (x.second > mt[max_occurrence_index])
        {
            max_occurrence_index = x.first;
        }
    }
    RotatetheVector(arr, 3);
    for (auto x : arr)
    {
        cout << x << " ";
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
