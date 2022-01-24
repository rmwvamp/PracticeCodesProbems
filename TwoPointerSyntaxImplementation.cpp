#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int ans = 0;

    int head = -1;
    int tail = 0;
    int cnt = 0;
    while (tail < head)
    {
        while (head + 1 < n && cnt0 + (1 - arr[head + 1]) <= k)
        {
            head++;
            cnt0 += (1 - arr[head]);
        }
        ans = max(ans, head - tail + 1);
        if (head >= tail)
        {
            cnt0 -= (1 - arr[tail]);
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << ans << endl;

    return 0;
}