#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int Visited[310][310];
    int n, m;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    bool check(int x, int y)
    {
        if (x >= 0 && y >= 0 && x < n && y < m && Visited[x][y] == 1)
        {
            return true;
        }
        return false;ithub
    }
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        Visited[x][y] = 0;
        for (int k = 0; k < 4; k++)
        {
            if (check(x + dx[k], y + dy[k]))
            {
                Visited[x + dx[k]][y + dy[k]] = 0;
                dfs(x + dx[k], y + dy[k], grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {

        n = grid.size();

        m = grid[0].size();
        int cnt = 0;
        memset(Visited, -1, sizeof(Visited));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                Visited[i][j] = (int)(grid[i][j] - '0');
            }
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {

                if (Visited[i][j] == 1)
                {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};

int main()
{

    return 0;
}
