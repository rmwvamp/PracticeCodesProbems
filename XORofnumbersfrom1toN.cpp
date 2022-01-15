#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 8;
    // cin >> n;
    // need to find 1^2^3^4^....15
    int temp = n % 4;
    switch (temp)
    {
    case 0:
        cout << n << endl;
        break;
    case 1:
        cout << "1" << endl;
        break;
    case 2:
        cout << n + 1 << endl;
        break;
    case 3:
        cout << "0" << endl;
        break;
    default:
        break;
    }
    return 0;
}