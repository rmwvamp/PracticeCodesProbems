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

/* Question







*/

/* Approach

We run a loop from i=0 to n-1 then find the corresponding largest r according to it.

I'll find the r using binary search.

We'll use prefix sum for array for this

Let' suppose we are creating the prefixsum of number of zeroes.

then, we know that the general condition is : prefixsum[r]-prefixsum[l-1]<=k

that is for a particular value of i, number of counts should be minimum while we try to make
the corresponding r larger.

SOME IMPORTANT UNDERSTANDING PART

We find the "r" by actually using upper bound, which itself uses binary search. O(logn)


SIMPLYFING THE EXPRESSION

prefixsum[r]-prefixsum[l-1]<=k

prefixsum[r]<=k+prefixsum[l-1]

I=> 0   1   2   3   4   5   6   7   8
A=> 0   1   1   0   0   1   1   0   1

P=> 1   1   1   2   3   3   3   4   4
k=2

Dry Run 1-
i=0, k=2.. we want an iterator having a value less than or equal to 2, => r=3 and if i take upper_bound(all(prefix),2) it would
return iterator 4.


I=> 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  
A=> 0   1   1   0   0   1   1   1   0   0   0   1   1   0   1

P=> 1   1   1   2   3   3   3   3   4   5   6   6   6   7   8

k=2

Dry Run 1-
i=0, k=3.. we want an iterator having a value less than or equal to 3, => r=7 and if i take upper_bound(all(prefix),2) it would
return iterator 8.





*/

void solve()
{
    // SOLUTION STARTS
    scii(n, k);
    vector<int> arr(n);
    vector<int> prefixsum(n);
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {   
        cin >> arr[i];
        prefixsum[i] = 1 - arr[i]; // this means that 1 would become 0 and 0 would become 1 by this simple magic. So, no we are counting the number of zeroes
        if (i)
            prefixsum[i] += prefixsum[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
        int temp = distance(prefixsum.begin() + i, upper_bound(prefixsum.begin() + i, prefixsum.end(), k + (i > 0 ? prefixsum[i - 1] : 0)));
        ans = max(ans, temp);
    }

    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
