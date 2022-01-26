#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 0b1110011100;
    // cin >> n;
    int count = 0;
    for (int i = 0; n != 0; count++)
    {
        /* code */
        n = n & (n - 1);
    }
    cout << count << " With a Time Complexity of O(number of 1s)" << endl;

    return 0;
}