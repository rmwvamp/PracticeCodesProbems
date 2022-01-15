#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    // sum of and of all pairs
    for (int i = 0; i < 31; i++)
    {
        int count1 = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
            {
                count1++;
            }
        }
        ans = ans + (((count1 - 1) * count1) * (1 << i) * 1LL) / 2;
    }

    cout << (ans % 1000000007) << endl;
}