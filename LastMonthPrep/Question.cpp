#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[100010][100010];

    int rec(int Position, int Lane, int n)
    {
        if (Position < 0)
        {
            return 0;
        }

        if (dp[Position][Lane] == -1)
        {
            dp[Position][Lane] = (rec(Position - 1, (Lane + 1) % 2, n + 1) + 1) % 109 + 7;
        }
        return dp[Position][Lane];
    }

    int countHousePlacements(int n)
    {
        memset(dp, -1, sizeof(dp));
        return ((rec(0, 0, n)) % 109 + 7 + (rec(0, 1, n)) % 109 + 7) % 109 + 7;
    }
};