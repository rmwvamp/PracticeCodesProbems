#include <iostream>
#include <algorithm>
using namespace std;
int mod = 1e9 + 7;
bool checkString(string &s, int st, int ed)
{
    if (s[st] == '0' || s[st] == '2' || s[st] == '4' || s[st] == '6' || s[st] == '8')
    {
        if (s[ed] == '1' || s[ed] == '3' || s[ed] == '5' || s[ed] == '7' || s[ed] == '9')
        {
            return 1;
        }
    }
    return 0;
}

int partitionString(string &s, int k, int i, int m)
{
    if (i == s.size() && k == 0)
    {
        return 1;
    }
    if (i == s.size() || k == 0)
    {
        return 0;
    }
    int ans = 0;
    for (int idx = i + 1; s[idx]; idx++)
    {
        if (idx - i + 1 >= m && checkString(s, i, idx))
        {
            ans += partitionString(s, k - 1, idx + 1, m) % mod;
        }
    }
    return ans;
}

int main()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k;
    cin >> s;
    cout << partitionString(s, k, 0, m) << endl;
    return 0;
}

// long long MOD=1e9+7;
// void helper (vector<int> &C,vector<int>&adj, int vertex,vector<bool>&visited, unordered_map<int,int> &m, int len, int &ans){
//     if (visited[vertex])
//     return;
    
//     visited[vertex] = true;
//     m[C[vertex-1]]++;
//     len = len+1;
    
//     if (m[C[vertex-1]] >= ceil((double)len/(double) 2)){
//         ans += 1;
//     }
    
//     for (auto itr != adj[vertex].begin (); itr != adj[vertex].end (); itr++){
//         helper (C,adj,*itr,visited,len,ans);
        
//         unordered_map<int,int> new_m;
//         helper (C,adj,*itr,visited,new_m,0,ans);
//     }
    
//     visited[vertex] = false;
//     m[C[veretx-1]]--;
//     return;
// }