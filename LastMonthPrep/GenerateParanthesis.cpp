#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    // here cnt-  represents the cnt of unclosed brackets
    void rec(int n, string s, int cnt)
    {
        // base case
        if (s.size() == n)
        {
            if (cnt == 0)
                ans.push_back(s);
            return;
        }

        if (cnt < 0)
        {
            return;
        }

        // recursive case
        rec(n, s + "(", cnt + 1);
        rec(n, s + ")", cnt - 1);
    }
    vector<string> generateParenthesis(int n)
    {
        rec(2 * n, "", 0);
        return ans;
    }
};