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
#define n_l '\n'
#define dbg(...)                          \
    cout << "[" << #__VA_ARGS__ << "]: "; \
    cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N>
int SIZE(const T (&t)[N])
{
    return N;
}
template <typename T>
int SIZE(const T &t) { return t.size(); }
string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool b) { return (b ? "true" : "false"); }
string to_string(const char c) { return string({c}); }
template <size_t N>
string to_string(const bitset<N> &b, int x1 = 0, int x2 = 1e9)
{
    string t = "";
    for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__)
    {
        t += b[__iii__] + '0';
    }
    return '"' + t + '"';
}
template <typename A, typename... C>
string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords);
int l_v_l_v_l = 0, t_a_b_s = 0;
template <typename A, typename B>
string to_string(const pair<A, B> &p)
{
    l_v_l_v_l++;
    string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
    l_v_l_v_l--;
    return res;
}
template <typename A, typename... C>
string to_string(const A(&v), int x1, int x2, C... coords)
{
    int rnk = rank<A>::value;
    string tab(t_a_b_s, ' ');
    string res = "";
    bool first = true;
    if (l_v_l_v_l == 0)
        res += n_l;
    res += tab + "[";
    x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
    auto l = begin(v);
    advance(l, x1);
    auto r = l;
    advance(r, (x2 - x1) + (x2 < SIZE(v)));
    for (auto e = l; e != r; e = next(e))
    {
        if (!first)
        {
            res += ", ";
        }
        first = false;
        l_v_l_v_l++;
        if (e != l)
        {
            if (rnk > 1)
            {
                res += n_l;
                t_a_b_s = l_v_l_v_l;
            };
        }
        else
        {
            t_a_b_s = 0;
        }
        res += to_string(*e, coords...);
        l_v_l_v_l--;
    }
    res += "]";
    if (l_v_l_v_l == 0)
        res += n_l;
    return res;
}
void dbgm() { ; }
template <typename Heads, typename... Tails>
void dbgm(Heads H, Tails... T)
{
    cout << to_string(H) << " | ";
    dbgm(T...);
}
#define dbgm(...)                         \
    cout << "[" << #__VA_ARGS__ << "]: "; \
    dbgm(__VA_ARGS__);                    \
    cout << endl

vector<int> DivisorsCount[int(1e5 + 1)];

void PreComputing_DivisorsofNumber()
{
    // doing it till 1e5
    for (int i = 1; i < 1e5 + 1; i++) // Putting factors/divisors at the number ith array position in the vector
    {
        for (int j = i; j < 1e5 + 1; j += i)
        {
            DivisorsCount[j].push_back(i);
        }
    }
}

ll BinaryExponentiation(ll base, ll exponent)
{
    ll ans = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            ans = (ans % mod) * (base % mod) % mod;
        }
        base = (base % mod) * (base % mod) % mod;
        exponent /= 2;
    }
    // cout << BinaryExponentiation(10, 3) << endl;
    return ans;
}

void solve()
{
    // cout << BinaryExponentiation(10, 3) << endl;
    // cout << BinaryExponentiation(8, 31) << endl;
    // cout << BinaryExponentiation(2, 9) << endl;
    sci(n);
    vector<int> arr(n);
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        sci(x);
        m[x]++;
    }
    sci(gcdnumber);
    int FrequencyCount[int(1e5 + 1)] = {0};
    dbg(m);
    // for (int i = 0; i < 30; i++)
    // {
    //     cout << "FrequencyCount: " << i << " " << FrequencyCount[i] << endl;
    // }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << "hello" << endl;
        auto kit = DivisorsCount[it->first].end();
        cout << kit - DivisorsCount[it->first].begin() << endl;
        // for (auto kit = DivisorsCount[it->first].begin(); kit != DivisorsCount[it->first].end(); kit++)
        // {
        //     cout << *kit << endl;
        //     FrequencyCount[*kit] += it->second;
        // }
        for (auto x : DivisorsCount[it->first])
        {
            cout << "hello2" << endl;
            FrequencyCount[x] += it->second;
        }
    }
    for (int i = 0; i < 30; i++)
    {
        cout << "FrequencyCount: " << i << " " << FrequencyCount[i] << endl;
    }
    // for (int i = 0; i < 1e3; i++)
    // {
    //     FrequencyCount[i] = (BinaryExponentiation(2, FrequencyCount[i]) - 1 + mod) % mod;
    // }
    // dbg(FrequencyCount);
    // for (int i = 0; i < 30; i++)
    // {
    //     cout << "FrequencyCount: " << i << " " << FrequencyCount[i] << endl;
    // }
    for (int i = 1e5; i >= 1; i--)
    {
        for (int j = 2 * i; j <= 1e5; j += i)
        {
            FrequencyCount[i] = ((FrequencyCount[i] - FrequencyCount[j] + mod) % mod);
        }
    }
    // for (int i = 0; i < 30; i++)
    // {
    //     cout << "FrequencyCount: " << i << " " << FrequencyCount[i] << endl;
    // }

    cout << FrequencyCount[gcdnumber] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    PreComputing_DivisorsofNumber;
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
