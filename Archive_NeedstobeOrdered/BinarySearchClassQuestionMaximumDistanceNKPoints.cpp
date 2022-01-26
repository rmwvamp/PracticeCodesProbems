#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int n, k;

int check(int x) // Checking if it would become the required sum
{
    int need = 0;
    for (int i = 1; i < n; i++)
    {
        /* code */
        int difference = arr[i] - arr[i - 1];
        need += ((difference + x - 1) / x) - 1;
    }
    return need <= k;
}

int main() // Binary Search
{
    // int n;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int lo = 1;
    int hi = 1e9;
    int ans = 1e9;
    int count = 0;
    while (lo <= hi)
    {
        count++;
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
        cout << "Iteration: " << count << " with lo: " << lo << " hi: " << hi << " ans : " << ans << endl;
    }

    cout << "Answer: " << ans << endl;
    // cout << "Count " << count << endl;

    return 0;
}

// 1.. 2. 3..4.. 5....1e9