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

class MyStructure
{

private:
    multiset<int> M1, M2;
    ll sum;
    int K;

public:
    MyStructure(int K) : K(K), sum(0LL){};

    void add(int x)
    {
        M1.insert(x);
        sum += x;
        if ((int)M1.size() > K)
        {
            int y = *(M1.begin());
            M1.erase(M1.find(y));
            sum -= y;
            M2.insert(y);
        }
        return;
    }

    void remove(int x)
    {
        if (M2.find(x) != M2.end())
        {
            M2.erase(M2.find(x));
        }
        else if (M1.find(x) != M1.end())
        {
            sum -= x;
            M1.erase(M1.find(x));
            if (M2.empty())
                return;
            int y = *(M2.rbegin());
            sum += y;
            M1.insert(y);
            M2.erase(M2.find(y));
        }
        return;
    }

    ll getSum()
    {
        return sum;
    }
};

bool cmp(vector<int> v1, vector<int> v2)
{
    int num = v1[1];
    int num2 = v1[1];
    return num < num2;
}

void solve()
{
    // SOLUTION STARTS
    scii(n, k);
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0]; // efficiency
        cin >> arr[i][1]; // speed
    }
    sort(all(arr), cmp);

    MyStructure M(k);
    for (int i = n - 1; i >= 0; i++)
    {
        int x = arr[i][0];
        MyStructure.add(M(x));
    }
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
