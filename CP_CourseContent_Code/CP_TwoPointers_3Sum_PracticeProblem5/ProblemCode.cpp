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

bool isPerfectSquare(long long x)
{
    long long s = sqrt(x);
    return (s * s == x);
}

bool isFibonacci(long long n)
{

    return isPerfectSquare(5 * n * n + 4) ||
           isPerfectSquare(5 * n * n - 4);
}

vector<bool> solution(vector<long long> a)
{
    vector<bool> ans;
    for (auto x : a)
    {
        ans.push_back(isFibonacci(x));
    }
    return ans;
}
int main()
{
    int n;cin>>n;
    vector<long long>array(n);
    for (int i = 0; i < n; i++)
    {
        cin>>array[i];
    }
    for(auto x: solution(array))
    {
        if(x)cout<<"YES"<<" ";
        else cout<<"NO ";
    }
    

    return 0;
}
