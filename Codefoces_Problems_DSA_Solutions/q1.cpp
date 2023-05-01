#include <bits/stdc++.h>
using namespace std;

#define int long long


void check()
{

}
signed main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string up;
        string down;
        int total = 0;
        cin >> up; 
        cin >> down;

        for (auto x : up)
        {
            int num = x - '0';
            if (num == 1)
            {
                total += 1;
            }
            if (num == 3)
            {
                total += 4;
            }
            if (num == 5)
            {
                total += 6;
            }
            if (num == 7)
            {
                total += 9;
            }
        }

        for (auto x : down)
        {
            int num = x - '0';
            if (num == 1)
            {
                total -= 1;
            }
            if (num == 3)
            {
                total -= 4;
            }
            if (num == 5)
            {
                total -= 6;
            }
            if (num == 7)
            {
                total -= 9;
            }
        }

        cout << total << endl;
    }

    return 0;
}