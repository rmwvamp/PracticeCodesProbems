#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> arr;

vector<vector<int>> Graph;

vector<vector<int>> Distance;

vector<vector<pair<int, int>>> Parent;

bool check(int x, int y)
{
    if (x < n && y < m && x >= 0 && y >= 0 && arr[x][y] != '#')
        return 1;
    else
        return 0;
}

int MovementsinX[] = {-1, 1, 0, 0};
int MovementsinY[] = {0, 0, 1, -1};

void BFS(pair<int, int> Point)
{
    queue<pair<int, int>> q;
    Distance = vector<vector<int>>(n, vector<int>(m, 1e9));
    Parent = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

    // Main BFS Code

    Distance[Point.first][Point.second] = 0;
    Parent[Point.first][Point.second] = make_pair(-1, -1);
    q.push(Point);
    while (!q.empty())
    {
        auto CurrentPosition = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            if (check(CurrentPosition.first + MovementsinX[k], CurrentPosition.second + MovementsinY[k]) && Distance[CurrentPosition.first + MovementsinX[k]][CurrentPosition.second + MovementsinY[k]] > Distance[CurrentPosition.first][CurrentPosition.second] + 1)
            {
                Distance[CurrentPosition.first + MovementsinX[k]][CurrentPosition.second + MovementsinY[k]] = Distance[CurrentPosition.first][CurrentPosition.second] + 1;
                Parent[CurrentPosition.first + MovementsinX[k]][CurrentPosition.second + MovementsinY[k]] = make_pair(CurrentPosition.first, CurrentPosition.second);
                q.push(make_pair(CurrentPosition.first + MovementsinX[k], CurrentPosition.second + MovementsinY[k]));
            }
        }
    }
}

void PrintPath(pair<int, int> en)
{
    if (en == make_pair(-1, -1))
    {
        return;
    }
    PrintPath(Parent[en.first][en.second]);
    cout << en.first << " " << en.second << endl;
}

int main()
{

    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    pair<int, int> Start, End;
    cin >> Start.first >> Start.second;
    cin >> End.first >> End.second;
    BFS(Start);
    cout << Distance[End.first][End.second] << endl;

    return 0;
}
