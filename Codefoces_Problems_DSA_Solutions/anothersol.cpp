#include <bits/stdc++.h>
using namespace std;

// #include <tr1/unordered_set>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

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

vector<int> DivisorsCount[int(1e5 + 2)];

void PreComputing_DivisorsofNumber()
{
    // doing it till 1e5
    for (int i = 1; i < 1e5 + 2; i++) // Putting factors/divisors at the number ith array position in the vector
    {
        for (int j = i; j < 1e5 + 2; j += i)
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

// ll gcd(ll a, ll b)
// {
//     if (a == 0 || b == 0)
//         return a ^ b;
//     else
//     {
//         return __gcd(a, b);
//     }
// }
vector<ll> is_prime(ll(1e5 + 100), 1);
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

vector<ll> Factorials(int(1e6 + 2));
vector<ll> InverseofFactorials(int(1e6 + 2));
void PreComputing_Factorials()
{
    Factorials[0] = 1;
    for (int i = 1; i < 1e6 + 2; i++)
    {
        /* code */
        Factorials[i] = (((Factorials[i - 1] % mod) * (i % mod) % mod));
    }

    // cout << Factorials[10] << endl;
}

void PreComputing_InversesofFactorials()
{
    InverseofFactorials[0] = 1;
    for (int i = 1; i < 1e6 + 2; i++)
    {
        /* code */
        InverseofFactorials[i] = BinaryExponentiation_Binpow(Factorials[i], mod - 2);
    }
    // for (int i = 0; i < 100; i++)
    // {
    // cout << InverseofFactorials[10] << endl;
    // }
}

void ReversetheArray(vector<ll> &arr, int start, int end)
{
    int mid = (end - start + 1) / 2;
    for (int i = start; i < start + mid; i++)
    {
        swap(arr[i], arr[end - i + start]);
    }
}

void RotatetheVector(vector<ll> &arr, int no_of_rotations)
{
    ReversetheArray(arr, arr.size() - no_of_rotations, arr.size() - 1);
    ReversetheArray(arr, 0, arr.size() - no_of_rotations - 1);
    ReversetheArray(arr, 0, arr.size() - 1);
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
ll SquareRoot_LL(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}
/*
Segment Tree Code
struct sgtnode
{// create structure
    sgtnode()
    {
    }
};
sgtnode merge(sgtnode &a, sgtnode &b)// designing in O(1) for having sgt in O(log(n))
{
    // condition for returning
}
void build(ll index, ll l, ll r, vector<ll> &arr, vector<sgtnode> &t)
{
    if (l == r)
    {
        // update this condition too
        t[index] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * index, l, mid, arr, t);
    build(2 * index + 1, mid + 1, r, arr, t);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}
void update(ll index, ll l, ll r, ll pos, ll val, vector<ll> &arr, vector<sgtnode> &t)
{
    if (pos < l || pos > r)
        return;
    if (l == r)
    {
        // update this condition
        t[index] = ;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * index, l, mid, pos, val, arr, t);
    update(2 * index + 1, mid + 1, r, pos, val, arr, t);
    t[index] = merge(t[2 * index], t[2 * index + 1]);
}
sgtnode query(ll index, ll l, ll r, ll lq, ll rq, vector<ll> &arr, vector<sgtnode> &t)
{
    if (l > rq || lq < r)
        return 0;
    if (lq <= l && r <= rq)
        return t[index];
    ll mid = (l + r) / 2;
    return merge(query(2*index,l, mid, lq, rq, arr, t), query(2*index+1,mid+1, r, lq, rq, arr, t));
}
*/

// Code for 1 state dp

// ll n;
// vector<ll> memo(1e6, -1);
// ll dp(ll i)
// {
//     // base case
// if(i<0)
// {
//     return 0;
// }
//     //
// if (memo[i] != -1)
// {
//     return memo[i];
// }
//     ll ans = 0;
//     return memo[i] = ans;
// }

// Code for 2 states dp

// vector<vector<ll>> memo(1e3, vector<ll>(1e3, -1));
// ll dp(ll i, ll j)
// {
//     // base case
//     if (i < 0 || j < 0)
//     {
//         return 0;
//     }

//     //
//     if (memo[i][j] != -1)
//     {
//         return memo[i][j];
//     }
//     ll ans = 0;

//     return memo[i][j] = ans;
// }

// void solve()
// {
//     // SOLUTION STARTS
//     sci(n);
//     vector<int> arr(n);
//     map<int, int> tempcount;
//     map<int, int> mmmp1;
//     int findmex = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         if (mmmp1.find(arr[i]) != mmp1.end())
//             tempcount[arr[i]] = arr[i];
//         mmp1[arr[i]]++;
//     }
//     for (auto val : mmp1)
//     {
//         if (findmex == val.first)
//             findmex++;
//     }
//     int r = -1;
//     int lo = -1;
//     int xx = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == findmex + 1)
//         {
//             xx = i;
//             lo = i;
//             break;
//         }
//         else
//             continue;
//     }
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (arr[i] == findmex + 1)
//         {
//             r = i;
//             break;
//         }
//     }

//     int nindmex = 0;
//     int yy = INT_MIN;

//     bool checkpossible = true;
//     if (lo != -1 && r != -1)
//     {
//         for (int i = lo; i <= r; i++)
//         {
//             arr[i] = findmex;
//             yy = findmex;
//         }
//     }
//     else
//         checkpossible = false;

//     if (checkpossible == true)
//     {
//         for (auto elem : mmp1)
//         {
//             if (elem.second > 1)
//             {
//                 cout << "Yes" << endl;
//                 return;
//             }
//         }
//     }
//     int count = 0;
//     sort(all(arr));
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == nindmex)
//         {
//             nindmex++;
//         }
//         count = max(count, nindmex);
//     }
//     if (xx == yy)
//         count = xx;
//     if (nindmex == findmex + 1)
//     {
//         cout << "Yes" << endl;
//         return;
//     }
//     cout << "No" << endl;

//     // vector<vector<ll>> arr(n, vector<ll>(m, -1));for (int i = 0; i < n; i++){for (int j = 0; j < m; j++){cin >> arr[i][j];}}
// }
void anothersolve()
{
    sci(n);
    vector<int> arr(n);
    map<int, int> mmp1;
    int MEX = 0;
    map<int, int> tempmmp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mmp1[arr[i]]++;
        if (tempmmp.find(arr[i]) != tempmmp.end())
            tempmmp[arr[i]]++;
    }
    for (auto al : mmp1)
    {
        if (MEX == al.first)
            MEX++;
        else
            continue;
    }
    int l = -1;
    int r = -1;
    int xx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == MEX + 1)
        {
            l = i;
            xx = i;
            break;
        }
        else
        {
            continue;
        }
    }
    int yy = 0;
    bool check = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == MEX + 1)
        {
            r = i;
            yy = i;
            break;
        }
        else
        {
            continue;
        }
    }
    int tcount = 0;
    if (l != -1 && r != -1)
    {
        for (int i = l; i <= r; i++)
        {
            arr[i] = MEX;
            tcount++;
        }
    }
    else
    {
        check = false;
    }
    if (!check)
    {
        for (auto p : mmp1)
        {
            if (p.second > 1)
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    sort(all(arr));
    int nMEX = 0;
    int val = MEX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == nMEX)
            nMEX++;
        else
            continue;
    }
    if (xx == yy)
        tcount = xx;
    if (nMEX == MEX + 1)
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}
// vector<ll> checksolve(int n, vector<ll> arr)
// {
//     map<int, vector<int>> mp;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         mp[arr[i]].push_back(i);
//     }
//     // dbgm(mp);
//     int mex = 0;
//     vector<ll> copyarr = arr;
//     sort(all(copyarr));
//     for (int i = 0; i < n; i++)
//     {
//         if (copyarr[i] == mex)
//             mex++;
//         else
//             break;
//     }
//     // dbgm(mex);

//     if (n == 1 && arr[0] == 1)
//     {
//         cout << "Yes" << endl;
//         return;
//     }
//     if (mex == n)
//     {
//         cout << "No" << endl;
//         return;
//     }
//     vector<int> check;
//     if (mp.find(mex + 1) != mp.end())
//     {
//         check = mp[mex + 1];
//     }
//     if (check.size() == 0)
//     {
//         cout << "Yes" << endl;
//         return;
//     }
//     map<int, int> checkmp;
//     sort(all(check));
//     for (int i = 0; i < check[0]; i++)
//     {
//         /* code */
//         checkmp[arr[i]]++;
//     }
//     for (int i = check[check.size() - 1] + 1; i < arr.size(); i++)
//     {
//         /* code */
//         checkmp[arr[i]]++;
//     }
//     // dbgm(checkmp);
//     for (int i = check[0]; i <= check[check.size() - 1]; i++)
//     {
//         /* code */
//         if (arr[i] >= mex)
//             continue;
//         else if (arr[i] < mex && checkmp.find(arr[i]) != checkmp.end())
//             continue;
//         else
//         {
//             cout << "No" << endl;
//             return;
//         }
//     }

//     cout << "Yes" << endl;
// }
void TestCaseGenerator()
{
    for (int i = 0; i < 100; i++)
    {
        ll n = rand() % 15 + 1;
        vector<ll> test;
        for (ll j = 0; j < n; j++)
        {
            test.push_back(rand() % 50 + 1);
        }
        // vector<int> test = {0, 9, 2, 1, 4, 3};shuffle(test.begin(), test.end(), rand());
        dbgm(n, test);
        // ll sol1 = checksolve(n, test);ll sol2 = brutesolve(n, test);if (sol1 != sol2){dbgm(test, n, sol1, sol2);}
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)

        anothersolve();
    // anothersolve();
    // TestCaseGenerator();
    return 0;
}