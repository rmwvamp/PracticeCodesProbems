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

void Permutation_of_String(string &str, int i)
{
    if (i == str.size())
    {
        cout << str << endl;
        return;
    }
    for (int j = i; j != str.size(); j++)
    {
        swap(str[i], str[j]);
        Permutation_of_String(str, i + 1);
        swap(str[i], str[j]);
    }
}

vector<vector<int>> ans;
void Array(vector<int> &nums, int i)
{
    if (i == nums.size())
        ans.push_back(nums);
    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        Array(nums, i + 1);
        swap(nums[i], nums[j]);
    }
}



// Time Complexity -> O(n! * n)
// Auxilary Space Complexity -> O(n) used by recursion stack
// Answer Space Complexity ->  O(n!) for storing all answers

void solve()
{

    // SOLUTION STARTS
    scs(str);
    Permutation_of_String(str, 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
