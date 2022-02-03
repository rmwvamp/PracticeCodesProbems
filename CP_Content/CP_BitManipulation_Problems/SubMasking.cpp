#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0b10101;
    string arr[5] = {"a",
                     "s", // sanyam
                     "c",
                     "m", // mayank
                     "e"};
    // cin >> n;
    /* here 10101, 0 represents sanyam and mayank, now i want to create subsets in a manner that:
    sanyam and mayank never gets anything according to set, that is they are always zero..*/
    for (int sub = n, count = 1; sub; sub = (sub - 1) & n, count++)
    {
        /* code */
        int num = sub;
        cout << "Subset " << count << ": ";
        for (int i = 0; i < 5; i++)
        {
            /* code */
            if (num & 1)
            {
                cout << " " << arr[i] << " ";
            }
            else
            {
                cout << " _ ";
            }
            num /= 2;
        }
        cout << endl;
    }

    return 0;
}