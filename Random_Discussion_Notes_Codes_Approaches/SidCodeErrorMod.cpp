#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

void solve();

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> factorial(n + 1);
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            factorial[i] = 1;
        }
        else
        {
            factorial[i] = (i % mod) * (factorial[i - 1] % mod) % mod;
        }
    }
}