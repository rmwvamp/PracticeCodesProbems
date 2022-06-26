
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memo[110];
    int rob(vector<int> &nums)
    {
        memset(memo, -1, sizeof(memo));
        int res = dp(nums.size() - 1, nums);
        return res;
    }
    int dp(int i, vector<int> &nums)
    {
        if (i == 0)
        {
            return memo[i] = nums[i];
        }
        if (i == 1)
        {
            return memo[i] = max(nums[0], nums[1]);
        }
        if (memo[i] == -1)
        {
            memo[i] = max(dp(i - 2, nums) + nums[i], dp(i - 1, nums));
        }
        return memo[i];
    }
};
