#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100100];

int check(int x)
{
    return arr[x] >= arr[0];
}

int main()
{
    // int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo = 0;
    int hi = n - 1;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            lo = mid + 1;
        }
        else
        {
            ans = mid;
            hi = mid - 1;
        }
    }
    return 0;
}

/* YYYYYYNN

YYYYYYYYYYYYYYYYYYYYNN
   8


NNYYYYYY




*/