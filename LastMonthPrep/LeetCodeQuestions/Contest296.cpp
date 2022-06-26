#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMaxGame(vector<int> &nums)
    {
        vector<int> ans = nums;
        int length = ans.size();
        while (ans.size() > 1)
        {
            vector<int> temp;
            for (int i = 0; i < ans.size() / 2; i++)
            {
                if (i % 2 == 0)
                {
                    temp.push_back(min(ans[2 * i], ans[2 * i + 1]));
                }
                else
                {
                    temp.push_back(max(ans[2 * i], ans[2 * i + 1]));
                }
            }
            ans.clear();
            ans.assign(temp.begin(), temp.end());
        }
        int res = 0;
        for (auto x : ans)
        {
            res = max(res, x);
        }
        return res;
    }
};

int main()
{

    return 0;
}
