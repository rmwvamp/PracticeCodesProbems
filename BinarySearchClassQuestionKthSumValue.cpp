#include <bits/stdc++.h>
using namespace std;

int arr[1000100];
int brr[1000100];

int n, m, k;

int check(int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += upper_bound(brr, brr + m, x - arr[i]) - brr;
    }

    return ans <= k;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    sort(arr, arr + n);
    sort(brr, brr + m);
    int lo = 1;
    long long hi = 1e10;
    int ans = -1;

    while (lo <= hi)
    {
        long long mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}

/*

arr -> n

brr -> m

1   2   2   2   3   6   7

arr[i] + brr[j]<=k

b[i]<=x-arr[i]




 */