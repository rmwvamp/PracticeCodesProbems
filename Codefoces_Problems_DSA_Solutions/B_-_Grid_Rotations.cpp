#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_H = 1e5 + 5, MAX_W = 1e5 + 5;

ll H, W, Q;
char grid[MAX_H][MAX_W];
ll bitmask; // bitmask to keep track of the rotated regions

void rotate(ll a, ll b)
{
    // check if the first region (top left) has been rotated or not
    if (!(bitmask & 1))
    {
        for (ll i = 0; i < a; i++)
        {
            for (ll j = 0; j < b; j++)
            {
                swap(grid[i][j], grid[a - 1 - i][b - 1 - j]);
            }
            reverse(grid[i], grid[i] + b);
        }
    }

    // check if the second region (top right) has been rotated or not
    if (!(bitmask & 2))
    {
        for (ll i = 0; i < a; i++)
        {
            for (ll j = b; j < W; j++)
            {
                swap(grid[i][j], grid[a - 1 - i][2 * b - 1 - j]);
            }
            reverse(grid[i] + b, grid[i] + W);
        }
    }

    // check if the third region (bottom left) has been rotated or not
    if (!(bitmask & 4))
    {
        for (ll i = a; i < H; i++)
        {
            for (ll j = 0; j < b; j++)
            {
                swap(grid[i][j], grid[2 * a - 1 - i][b - 1 - j]);
            }
            reverse(grid[i], grid[i] + b);
        }
    }

    // check if the fourth region (bottom right) has been rotated or not
    if (!(bitmask & 8))
    {
        for (ll i = a; i < H; i++)
        {
            for (ll j = b; j < W; j++)
            {
                swap(grid[i][j], grid[2 * a - 1 - i][2 * b - 1 - j]);
            }
            reverse(grid[i] + b, grid[i] + W);
        }
    }

    // set the corresponding bits in the bitmask for the regions that have been rotated
    bitmask |= 1 << (a >= 1);
    bitmask |= 1 << (b >= 1);
    bitmask |= 1 << (a < H - 1);
    bitmask |= 1 << (b < W - 1);
}

int main()
{
    cin >> H >> W >> Q;

    // input grid
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            cin >> grid[i][j];
        }
    }

    while (Q--)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        rotate(a, b);
    }

    // prll the final grid
    for (ll i = 0; i < H; i++)
    {
        for (ll j = 0; j < W; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
