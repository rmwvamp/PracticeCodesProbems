#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0b111001100; // check if 2nd bit is set
    // cin >> n;
    int i = 4;
    if ((n >> i) & 1)
    {
        cout << "Bit is set" << endl;
        /* code */
    }
    else
    {
        cout << "Bit is not set" << endl;
    }

    if (n & (1LL << i))
    {
        cout << "Bit is set using 2nd if too" << endl;
        /* code */
    }
    else
    {
        cout << "Bit is not set using 2nd if too" << endl;
    }

    return 0;
}