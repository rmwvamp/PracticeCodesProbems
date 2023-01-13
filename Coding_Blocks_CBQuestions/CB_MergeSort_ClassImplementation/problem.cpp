#include <bits/stdc++.h>
#define Q 100010
#define N 5010
using namespace std;
struct Info
{
    int opt, x, y, dir, len;
} a[Q];
int s[2][N][N * 2], n, q, an[Q];
int lo(int x) { return x & (-x); }
void add(int x, int y, int p, int q)
{
    for (int i = x; i <= n; i += lo(i))
        for (int j = y; j <= n * 2; j += lo(j))
            s[p][i][j] += q;
}
int que(int p, int x, int y)
{
    int su = 0;
    for (int i = x; i > 0; i -= lo(i))
        for (int j = y; j > 0; j -= lo(j))
            su += s[p][i][j];
    return su;
}
int main()
{
    cin >> n >> q;
    int count = 0;
    for (int i = 1; i <= n + q; i++)
    {
        count++;
        if (count <= n)
            a[i].opt = 1;
        else
            a[i].opt = 2;
        if (a[i].opt == 1)
        {
            a[i].dir = 1;
            cin >> a[i].x >> a[i].y >> a[i].len;
            a[i].dir = 5 - a[i].dir;
            if (a[i].dir >= 3)
                a[i].dir = 7 - a[i].dir;
        }
        else
            cin >> a[i].x >> a[i].y;
    }
    for (int di = 1; di <= 4; di++)
    {
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n + q; i++)
        {
            if (a[i].opt == 1)
            {
                if (a[i].dir == di)
                {
                    add(a[i].x - a[i].len, a[i].x + a[i].y - a[i].len, 0, 1);
                    add(a[i].x + 1, a[i].x + a[i].y - a[i].len, 0, -1);
                    add(a[i].x - a[i].len, a[i].y + 1, 1, -1);
                    add(a[i].x + 1, a[i].y + 1, 1, 1);
                }
            }
            else
                an[i] += que(0, a[i].x, a[i].x + a[i].y) + que(1, a[i].x, a[i].y);
        }
        for (int i = 1; i <= n + q; i++)
        {
            swap(a[i].x, a[i].y);
            a[i].x = n + 1 - a[i].x;
        }
    }
    for (int i = 1; i <= n + q; i++)
        if (a[i].opt == 2)
            cout << an[i] << endl;
    return 0;
}
