#include <iostream>
#include <string>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
long long custombbs2(vector<int> &arr, int lo, int hi, int tar)
{
    int ans = arr.size();
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] >= tar)
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}
long long custombbs(vector<int> &arr, int lo, int hi, int tar)
{
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] <= tar)
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {

        // SOLUTION STARTS

        int n, k;
        unordered_map<int, int> countmap, count2map;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)

            cin >> arr[i];

        for (int i = 1; i <= n; i++)
        {
            countmap[i] = arr[i - 1];
        }
        sort(arr.begin(), arr.end());
        vector<int> r(n), l(n);

        for (int i = 0; i < n; i++)
        {
            int x = custombbs(arr, 0, i, arr[i] - k);
            if (x != -1)
            {
                l[i] += 1 + l[x];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int x = custombbs2(arr, i, n - 1, arr[i] + k);
            if (x != n)

                r[i] += 1 + r[x];
        }
        for (int i = 0; i < n; i++)

            l[i] = l[i] + 1 + r[i];

        for (int i = 0; i < n; i++)
        {
            count2map[arr[i]] = l[i];
        }
        string sb;
        for (int i = 1; i <= n; i++)
        {
            sb += to_string(count2map[countmap[i]]) + " ";
        }
        cout << "Case #" << t << ": " << sb << endl;
    }
    return 0;
}
