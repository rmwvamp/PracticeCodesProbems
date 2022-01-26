#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int n;

int check(int x)
{
    return arr[x] > arr[x - 1];
}
int main()
{
    // int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo = 1;
    int hi = n - 1;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
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

        cout << arr[ans] << endl;

    return 0;
}