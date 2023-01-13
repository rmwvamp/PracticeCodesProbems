#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
double n, q;
vector<pair<double, double>> datacentre;
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool isInside(double x1, double y1, double x2, double y2, double x3, double y3, double x, double y)
{

    double A = area(x1, y1, x2, y2, x3, y3);

    double A1 = area(x, y, x2, y2, x3, y3);

    double A2 = area(x1, y1, x, y, x3, y3);

    double A3 = area(x1, y1, x2, y2, x, y);

    return (A == A1 + A2 + A3);
}
void solve()
{
    double x, y, d;
    cin >> x >> y >> d;
    double count = 0;
    double a = x + d;
    double b = y + d;
    for (auto num : datacentre)
    {
        if (isInside(a, y, x, y, x, b, num.first, num.second))
            count++;
    }
    cout << count << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        freopen("data_centers_hard_input.txt", "r", stdin);
        freopen("data_centers_hard_sample_final1_shoaib.txt", "w", stdout);

    cin >> n >> q;
    datacentre.resize(n);
    for (double i = 0; i < n; i++)
    {
        cin >> datacentre[i].first >> datacentre[i].second;
    }
    while (q--)
    {
        solve();
    }
}