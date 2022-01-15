#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10; // constraint n<31
    int arr[n] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // BitMaskingCode

    int count = 0;

    for (int i = 1; i <= (1 << n); i++, count++)
    {
        /* code */
    }
    cout << "The number of subsets are " << count << endl;

    // Printing Subsets
    for (int i = 1; i <= (1 << n); i++, count++)
    {
        /* code */
        int num = i;
        cout << "Subset " << i << ": ";
        for (int j = 0; j < n; j++)
        {

            /* code */
            if (num & 1)
            {
                cout << " " << arr[j] << " ";
            }
            else
            {
                cout << " _ ";
            }
            num /= 2;
        }
        cout << endl;
    }

    /* Time Complexity => ek loop chalega he count karney keh liye bhi toh it would have been O(2^n)
for printing i',m creating an additional loop with n loop.. so, T.C. is O((2^n)*n) */
    return 0;
}