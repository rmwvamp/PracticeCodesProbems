#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vi;
    int n = 9;
    // cin >> n;

    /* code */
    // int x;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(4);
    vi.push_back(5);

    // vector<int> count(32, 0);
    // vector<pair<int, int>> prefixsum;
    int prefixsum[n][3] = {0};
    for (int i = 0; i < n; i++) // O(N*3)
    {

        for (int j = 0; j < 3; j++)
        {
            /* code */
            if (vi[i] & (1 << j))
            {
                // prefixsum.push_back(make_pair(vi[i][j], ))
                prefixsum[i][j]++;
            }
            if (i >= 1)
                prefixsum[i][j] += prefixsum[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) // O(N*3)
    {

        for (int j = 0; j < 3; j++)
        {
            /* code */
            cout << prefixsum[i][j];
        }
        cout << endl;
    }
    int q = 1;
    // cin >> q;
    while (q--)
    {
        // scii(x, y);
        // query.pb({x, y});
        int l = 1, r = 5;
        // cin >> l >> r;
        int x1 = 0;
        for (int i = 0; i < 3; i++)
        {
            /* code */
            float temp = ((r - l + 1 - 2 * prefixsum[r][i] + 2 * prefixsum[l - 1][i])) / 2.0;
            int bitcontribution;
            if (temp >= 1)
            {
                bitcontribution = 1;
            }
            else
            {
                bitcontribution = 0;
            }
            cout << "bitcontribution for " << i << " " << bitcontribution << endl;
            x1 += pow(2, i) * bitcontribution;
        }
        cout << "Ans :" << x1 << endl;

        /* code */
    }
    return 0;
}