#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int n, k;

int check(int x)
{
    int needed_points = 0;
    for (int i = 1; i < n; i++)
    {
        int difference = (arr[i] - arr[i - 1] + x - 1) / x - 1;
        needed_points += difference;
    }
    if (needed_points <= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lo = 1;
    int hi = 1e9;
    int ans = 1e9;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}