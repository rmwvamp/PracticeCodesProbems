#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 998244353
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define INF (1LL << 60)
#define NINF -INF
#define endl "\n"

int main()
{
    int t;
    cin >> t;
    vector<int> inverse;
    for (int i = 0; i < 100; i++)
    {
        inverse.push_back(i);
    }
    inverse.push_back(mod);

    for (int i = 1; i <= t; i++)
    {
        string result = "NO";
        unordered_map<char, int> mp;
        unordered_map<char, int> temp;
        for (int j = 0; j < 26; j++)
        {
            int c;
            cin >> c;
            mp[char(j + 'A')] = c;
            if (c == 'B')
                temp[c]++;
        }
        int n;
        cin >> n;

        unordered_map<string, int> wlist;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            string word;
            cin >> word;
            string w = "";
            for (char c : word)
            {
                string extra = to_string(mp[c]);
                w += extra;
                if (c == 'B')
                    flag = 1;
            }
            if (wlist.count(w) > 0)
            {
                result = "YES";
            }
            else
            {
                wlist[w] = 1;
            }
        }

        cout << "Case #" << i << ": " << result << endl;
    }
    return 0;
}