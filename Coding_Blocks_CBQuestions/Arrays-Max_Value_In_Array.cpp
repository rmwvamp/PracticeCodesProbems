#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    long long arr[n];

    long long sum = LONG_MIN;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = max(sum, arr[i]);
    }
    cout << sum << endl;
    return 0;
}