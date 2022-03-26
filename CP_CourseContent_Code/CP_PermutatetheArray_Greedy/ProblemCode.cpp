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
        swap(arr[i].second, arr[end - i + start].second);
    }
}

void RotatetheVector(auto &arr, int no_of_rotations)
{
    ReversetheArray(arr, arr.size() - no_of_rotations, arr.size() - 1);
    ReversetheArray(arr, 0, arr.size() - no_of_rotations - 1);
    ReversetheArray(arr, 0, arr.size() - 1);
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    vector<pair<ll, ll>> arr;
    map<ll, ll> mt;
    int max_occurrence_value = 0;
    for (int i = 0; i < n; i++)
    {
        sci(x);
        arr.pb({x, i});
        mt[x]++;
    }

    for (auto x : mt)
    {
        if (x.second > mt[max_occurrence_value])
        {
            max_occurrence_value = x.first;
        }
    }
    // making array sorted so that it has the same logic as the sorted one

    sort(all(arr), cmp);
    RotatetheVector(arr, mt[max_occurrence_value]);

    vector<ll> FinalArray(n);
    for (int i = 0; i < n; i++)
    {
        FinalArray[arr[i].second] = arr[i].first;
    }

    int score = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first != FinalArray[i])
        {
            score++;
        }
    }

    cout << score<<endl;
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
