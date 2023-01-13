// C++ program of the above approach
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fork(k, n) for (int i = k; i < n; ++i)
#define fori(n) for (int i = 0; i < n; ++i)
#define rfor(n) for (int i = n - 1; i >= 0; ++i)
#define forj(n) for (int j = 0; j < n; ++j)
ll gcd(ll a, ll b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> VS;
typedef map<int, int> mpii;

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Function to concatenate the
// given array arr[] twice
void concatThrce(vector<int> &arr, int N)
{
    // Stores array after
    // concatenation
    int newArr[3 * N];

    // Loop to iterate arr[]
    for (int i = 0; i < N; i++)
    {
        newArr[i] = arr[i];
        newArr[i + N] = arr[i];
    }

    // Print Answer
    for (int i = 0; i < 3 * N; i++)
    {
        cout << newArr[i] << " ";
    }
}

void harsh(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() / 2; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// void leetcode(vector<int> &changed)
// {
//     int n = changed.size();
//     if (n % 2 == 1)
//         return {};
//     sort(changed.begin(), changed.end());
//     vector<int> ans;
//     map<int, int> mp;
//     for (int i = 0; i < n; i++)
//     {
//         mp[changed[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (mp[changed[i]] == 0)
//             continue;
//         if (mp[changed[i] * 2] == 0)
//             return {};
//         ans.push_back(changed[i]);
//         mp[changed[i]]--;
//         mp[changed[i] * 2]--;
//     }
//     return ans;
// }

void solve()
{
    int n;
    cin >> n;
    int arr[n];
    fori(n)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    mpii ch;
    fori(n)
    {
        ch[arr[i]] = i;
    }
    mpii idx;
    vi ans;
    fori(n)
    {
        if (!idx[i])
        {
            idx[ch[arr[i] * 3]]++;
            ans.push_back(arr[i]);
        }
    }
    fori(ans.size())
            cout
        << ans[i] << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    map<int, int> ch;
    for (int i = 0; i < n; i++)
    {
        ch[arr[i]]++;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int freq = ch[arr[i]];
        if (freq > 0)
        {
            ans.push_back(arr[i]);
            ch[arr[i]]--;
            if (ch[3 * arr[i]] == 0)
            {
                cout << -1 << endl;
                return 0;
            }
            ch[3 * arr[i]]--;
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}
