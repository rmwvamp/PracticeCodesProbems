#include <bits/stdc++.h>
using namespace std;

int PartitionArray(vector<int> &arr, int s, int e)
{
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= arr[s])
            count++;
    }
    int Pivot_Index = s + count;
    swap(arr[s + count], arr[s]);
    int i = s, j = e;
    while (i < Pivot_Index && j > Pivot_Index)
    {
        while (arr[i] <= arr[Pivot_Index])
        {
            i++;
        }
        while (arr[j] > arr[Pivot_Index])
        {
            j--;
        }
        if (i < Pivot_Index && j > Pivot_Index)
            swap(arr[i++], arr[j--]);
    }
    return Pivot_Index;
}

void QuickSortAlgo(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    // find pivot->, then find the parition function, index would be returned
    int idx = PartitionArray(arr, s, e);

    // quick sort on both the  partitions- > before and after the pivot index

    QuickSortAlgo(arr, s, idx - 1);
    QuickSortAlgo(arr, idx + 1, e);
}

void solve()
{
    // SOLUTION STARTS
    int n;cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QuickSortAlgo(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
