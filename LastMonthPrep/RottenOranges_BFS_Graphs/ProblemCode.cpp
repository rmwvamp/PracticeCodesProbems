#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n, m;
    int TotalOranges, cntRotten;
    bool Check(int x, int y, vector<vector<int>> &grid)
    {
        if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1)
        {
            return true;
        }
        return false;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        TotalOranges = 0;
        cntRotten = 0;
        int days = 0;
        queue<pair<int, int>> q;
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                    TotalOranges++;
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j)); //
            }
        }

        while (!q.empty())
        {
            int k = q.size();
            cntRotten += k;
            while (k--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    if (Check(x + dx[k], y + dy[k], grid))
                    {
                        grid[x + dx[k]][y + dy[k]] = 2;
                        q.push(make_pair(x + dx[k], y + dy[k]));
                    }
                }
            }
            if (!q.empty())
                days++;
        }

        return TotalOranges == cntRotten ? days : -1;
    }
};

int main()
{

    return 0;
}
