#include <bits/stdc++.h>
using namespace std;
// doubt
int xornumbers1otn(int n)
{
    int temp = n % 4;
    switch (temp)
    {
    case 0:
        return n;
        break;
    case 1:
        return 1;
        break;
    case 2:
        return n + 1;
        break;
    case 3:
        return 0;
        break;
    default:
        break;
    }
}
int main()
{
    int l = 1;
    int r = 9;
    // cin >> n;
    // need to find 1^2^3^4^....15
    int ans = xornumbers1otn(l - 1) ^ xornumbers1otn(r);
    cout << ans << endl;
    cout << xornumbers1otn(l - 1) ^ xornumbers1otn(r) << endl;

    return 0;
}