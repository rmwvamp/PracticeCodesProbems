#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < operations.size(); i++)
        {
            int index = mp[operations[i][0]];
            mp[operations[i][1]] = index;
            mp[operations[i][0]] = -1;
        }
        vector<pair<int, int>> res;
        for (auto x : mp)
        {
            res.push_back(make_pair(x.second, x.first));
        }
        sort(res.begin(), res.end());
        vector<int> ans;
        for (int i = 0; i < res.size(); i++)
        {
            if (res[i].first != -1)
            {
                ans.push_back(res[i].second);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}
