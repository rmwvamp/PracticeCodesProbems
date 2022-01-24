#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int lo = 0;
    int hi = s.length() - 1;
    while (lo < hi)
    {
        if (s[lo] != s[hi])
        {
            cout << "No" << endl;
            break;
        }
        lo++;
        hi--;
    }
    if (lo >= hi)
        cout << "Yes" << endl;

    return 0;
}