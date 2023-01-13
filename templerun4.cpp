#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
// typedef tree<
//     int,
//     null_type,
//     less_equal<int>,
//     rb_tree_tag,
//     tree_order_statistics_node_update> ordered_set;
 
#define inp(n) ll n; cin >> n;
#define ina(a, n) ll a[n]; rep(i, 0, n){cin >> a[i];}
#define ll long long int
#define all(x) x.begin(), x.end()
#define rep(i, l, r) for(ll i =l; i<r; i++)
#define fr(i, l, r) for(int i =l; i<r; i++)
#define nrep(i, l, r) for(ll i =l; i>=r; i--)
#define ed << "\n"
#define pb push_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pi 2*acos(0.0);
#define minque priority_queue<ll, vector<ll>, greater<ll>>
#define maxque priority_queue<pair<int, vector<int>>>
#define popcount(x) __builtin_popcountll(x)
const unsigned int M = 1e9+7;
const unsigned int MOD = 998244353;
const int MAXN = 2e5+55;

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";}
template <typename A> ostream& operator<< (ostream &cout, set<A> const &v) {cout << "["; for(auto &x: v) cout << x <<" "; return cout << "]";}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }
 
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res%M * a%M)%M;
        a = (a%M * a%M)%M;
        b >>= 1;
    }
    return res%M;
} 



bool definitelyGreaterThan(long double a,long double b,long double epsilon)
{
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

bool definitelyLessThan(long double a, long double b, long double epsilon)
{
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
 
void testmetal(){   

	int n,q;
    cin >> n >> q;
    vector<long double> w(n+1);
    fr(i, 0, n){
        cin >> w[i+1];
    }

    long double hun = 100;
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            long double p1, p2, p3;
            int e, r;
            cin >> p1 >> p2 >> p3 >> e >> r;
            fr(i, 0, r){
                fr(j, 1, n+1){
                    if(definitelyLessThan(w[j], 1000000, 0.000000001)){

                        w[j]+=(p1*w[j])/hun;
                        long long int y = w[j];

                        long double frac = w[j]-y;
                        // cout << frac*1000000 ed;
                        long long int u = frac*1000000;
                       
                        
                        double fr = (long double)(u/1000000.0);
                        // if(j==2){
                        //     cout << w[j] << " "<<y << " "<<  frac << " "<< frac*1e6 << " "<< u << " "<< fr ed;
                        // }
                        w[j] = y+fr;
                    }else if(definitelyGreaterThan(w[j], 1000000, 0.0000000001) && definitelyLessThan(w[j], 2*1000000, 0.0000000001)){
                        w[j]+=(p2*w[j])/hun;
                        long long int y = w[j];
                        double frac = w[j]-y;
                        long long int u = frac*1000000;
                        double fr = (long double)(u/1000000.0);
                        // if(j==2){
                        //     cout << w[j] << " "<< u << " "<< fr ed;
                        // }
                        w[j] = y+fr;
                    }else{
                        w[j]+=(p3*w[j])/hun;
                        long long int y = w[j];
                        double frac = w[j]-y;
                        long long int u = frac*1000000;
                        double fr = (long double)(u/1000000.0);
                        // if(j==2){
                        //     cout << w[j] << " "<< u << " "<< fr ed;
                        // }
                        w[j] = y+fr;
                    }    
                }
                
                cout << fixed << setprecision(6) << w[e] ed;
            }
            
        }else{
            int e1, e2;
            cin >> e1 >> e2;
            long double sum = 0;
            fr(i, e1, e2+1){
                sum+=w[i];
            }
            cout << fixed << setprecision(6) << sum ed;
        }
    }



}
    
    
 
 
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // freopen("/Users/mayank/Downloads/promotions_hard_sample_input.txt" , "r" , stdin );
    // freopen("/Users/mayank/Downloads/answertry.txt" , "w" , stdout );
     
    ll t;
    cin >> t;
    // t=1;
 
    fr(mn, 0, t){
        // cout << "Case #" << mn +1 << ": ";
        testmetal();
        
    }
    return 0;
}