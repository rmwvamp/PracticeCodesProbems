
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memo[500010][3];
    int minSideJumps(vector<int> &obstacles)
    {
        memset(memo, -1, sizeof(memo));
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            ans = min(ans, dp(obstacles.size(), i, obstacles));
        }
        return ans;
    }
    int dp(int PointIndex, int PreviousLane, vector<int> &obstacles)
    {
        // base case
        if (PointIndex == 1)
        {
            if (PreviousLane == 1)
            {
                return memo[PointIndex][PreviousLane] = 0;
            }
            else
            {
                return memo[PointIndex][PreviousLane] = 1;
            }
        }
        if (memo[PointIndex][PreviousLane] == -1)
        {

            // recursive case
            if (obstacles[PointIndex - 1] != PreviousLane - 1)
            {
                memo[PointIndex][PreviousLane] = dp(PointIndex - 1, PreviousLane, obstacles);
            }
            else
            {
                // Check other two options
                int op1 = dp(PointIndex - 1, (PreviousLane + 1) % 3, obstacles);
                int op2 = dp(PointIndex - 1, (PreviousLane + 2) % 3, obstacles);

                memo[PointIndex][PreviousLane] = 1 + min(op1, op2);
            }
        }
        return memo[PointIndex][PreviousLane];
    }
};
int main()
{

    return 0;
}