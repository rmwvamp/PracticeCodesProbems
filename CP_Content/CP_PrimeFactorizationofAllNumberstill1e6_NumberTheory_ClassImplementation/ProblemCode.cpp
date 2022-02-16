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

// vector<bool> is_prime(1001000, 1);
// void Sieve_of_Eratosthenes(ll n)
// {
//     for (ll i = 2; i <= n; i++)
//     {
//         if (is_prime[i] == 1)
//         {
//             for (ll j = i * i; j <= n; j += i)
//             {
//                 is_prime[j] = 0;
//             }
//         }
//     }
// }

vector<ll> sp(1000100);
void Smallest_Prime_Array(ll n)
{
    for (int i = 2; i <= n; i++)
    {
        sp[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (sp[i] == i) // By iterating from 2 to n and having this condition, I'm able to iterate on the multiples of prime
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                if (sp[j] == j)
                {
                    sp[j] = i;
                }
            }
        }
    }
}

void solve()
{
    // SOLUTION STARTS
    sci(n);
    Smallest_Prime_Array(n);
    vector<vector<ll>> FinalResulting2DArray(n + 1);
    for (int i = 2; i <= n; i++)
    {
        ll number = i;
        vector<ll> temp;
        while (number > 1)
        {
            temp.pb(sp[number]);
            number /= sp[number];
        }
        FinalResulting2DArray[i] = temp;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < FinalResulting2DArray[i].size(); j++)
        {
            cout << FinalResulting2DArray[i][j] << " ";
        }
        cout << endl;
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
