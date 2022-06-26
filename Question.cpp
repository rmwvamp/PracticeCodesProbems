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
#define sci(x)   \
    long long x; \
    cin >> x
#define scii(x, y)  \
    long long x, y; \
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

ll BinaryExponentiation_Binpow(ll base, ll exponent)
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
    return ans % mod;
}

ll BinaryExponentiation_Binpow_WithoutMod(ll base, ll exponent)
{
    ll ans = 1;
    while (exponent)
    {
        if (exponent & 1)
        {
            ans = (ans) * (base);
        }
        base = (base) * (base);
        exponent /= 2;
    }
    return ans;
}

ll gcd(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a ^ b;
    else
    {
        return __gcd(a, b);
    }
}
vector<ll> is_prime(1000100, 1);
void Sieve_of_Eratosthenes(ll n)
{
    for (ll i = 2; i <= n; i++)
    {
        if (is_prime[i] == 1)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

vector<ll> Factorials(int(1e6 + 1));
vector<ll> InverseofFactorials(int(1e6 + 1));
void PreComputing_Factorials()
{
    Factorials[0] = 1;
    for (int i = 1; i < 1e6 + 1; i++)
    {
        /* code */
        Factorials[i] = (((Factorials[i - 1] % mod) * (i % mod) % mod));
    }

    // cout << Factorials[10] << endl;
}

void PreComputing_InversesofFactorials()
{
    InverseofFactorials[0] = 1;
    for (int i = 1; i < 1e6 + 1; i++)
    {
        /* code */
        InverseofFactorials[i] = BinaryExponentiation_Binpow(Factorials[i], mod - 2);
    }
    // for (int i = 0; i < 100; i++)
    // {
    // cout << InverseofFactorials[10] << endl;
    // }
}
ll CountDigitsofNumber(ll n)
{
    ll count = 0;
    while (n)
    {
        count++;
        n = n & (n - 1);
    }
    return count;
}

void solve()
{
    // SOLUTION STARTS

    // sci(n);vector<ll> arr(n);for (int i = 0; i < n; i++) {cin >> arr[i]; }
    // int count = 1;
    // vector<int> nums;
    // for (int i = 1; i <= 9; i++)
    // {
    //     nums.pb(i);
    // }
    sci(n);
    vector<int> ans;
    int sum = 0;
    int PrevDigit = -1;
    if (n > 9)
    {
        while (sum <= n)
        {
            cout << "Hello" << endl;
            for (int i = 9; i >= 1; i--)
            {
                cout << "Hello1" << endl;
                /* code */
                if (sum + i <= n && i != PrevDigit)
                {
                    PrevDigit = i;
                    ans.pb(i);
                    sum += i;
                    // dbg(sum);
                    // dbg(ans);
                    break;
                }
                else
                {
                    continue;
                }
            }
            if (sum == n)
            {
                break;
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
        }

        cout << endl;
    }
    else
    {
        cout << n << endl;
    }
}

void SecondSolve()
{
    sci(n);
    vector<int> nums;
    for (int i = 1; i <= 9; i++)
    {
        /* code */
        nums.pb(i);
    }
    vector<vector<int>> ans;
    for (int mask = 0; mask < (1 << 9); mask++)
    {
        /* code */
        vector<int> temp;
        for (int j = 0; j < 9; j++)
        {
            if (mask & (1 << j))
            {
                temp.pb(nums[j]);
            }
        }

        ll sum = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            sum += temp[i];
        }
        if (sum == n)
        {

            ans.pb(temp);
        }
    }
    dbgm(ans);
    vector<int> Finalnums;
    for (int i = 0; i < ans.size(); i++)
    {
        ll res = 0;
        for (int j = 0; j < ans[i].size(); j++)
        {

            res += BinaryExponentiation_Binpow(10, j) * res + ans[i][j];
        }
        Finalnums.pb(res);
    }
    sort(all(Finalnums), greater<int>());
    dbgm(Finalnums);
    cout << Finalnums[0] << endl;
}




int main()
{
    int n = 5;
    vector<int> dp(n + 1);
    for (int i = 0; i <= n + 1; i++)
    {
        dp[i] = (i * (i + 1)) / 2;
        if (i)
        {
            dp[i] += dp[i - 1];
        }
    }
    cout << dp[2] << endl;



    return 0;
}
