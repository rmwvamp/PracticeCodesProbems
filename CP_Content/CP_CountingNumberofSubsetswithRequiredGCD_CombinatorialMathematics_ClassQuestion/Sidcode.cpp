#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector< vector<int> > divi(100001);
#define mod 1000000007

void pre()
{
    for(int i = 1 ; i <= 100000 ; i++)
    {
        for(int j = i ; j <= 100000 ; j += i)
        {
            divi[j].push_back(i);
        }
    }
}

int binExpo(ll a, ll b)
{
    ll ans = 1;
    while(b)
    {
        if(b&1){
            ans = ((ans%mod)*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b = b/2;
    }
    return ans;
}

void solve()
{
    int n, k;
    cin>>n>>k;
    map <int, int> mp;
    for(int i = 0 ; i < n ; i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    vector<int> v(100001);
    for(auto x: mp)
    {
        for(auto y: divi[x.first])
        {
            v[y] += x.second;
        }
    }
    for(int i = 0 ; i < 100001 ; i++)
    {
        v[i] = binExpo(2, v[i]) - 1;
    }
    for(int i = 100000 ; i >= 1 ; i--)
    {
        for(auto x: divi[i])
        {
            if(x != i){
                v[x] -= v[i];
            }
        }
    }
    cout<<v[k]<<endl;
}

int main()
{
    pre();
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}