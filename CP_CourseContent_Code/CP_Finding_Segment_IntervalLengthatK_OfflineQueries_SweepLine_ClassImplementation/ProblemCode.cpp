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
    vector<pair<ll, pair<ll, ll>>> event;
    for (int i = 0; i < n; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;

        event.pb({l, {1, x}});
        event.pb({r, {3, x}});
    }

    sci(q);
    for (int i = 0; i < q; i++)
    {
        sci(y);
        event.pb({y, {2, i}});
    }

    sort(event.begin(), event.end());

    multiset<ll> mt;
    ll AnswerQuery[q];

    for (int i = 0; i < event.size(); i++)
    {
        if (event[i].second.first == 1)
        {
            mt.insert(event[i].second.second);
        }
        else if (event[i].second.first == 2)
        {
            if (mt.empty())
            {
                AnswerQuery[event[i].second.second] = -1;
            }
            else
            {
                AnswerQuery[event[i].second.second] = *mt.rbegin();
            }
        }
        else
        {
            mt.erase(mt.find(event[i].second.second));
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << AnswerQuery[i] << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;cin >> t;while (t--)
    solve();

    return 0;
}
