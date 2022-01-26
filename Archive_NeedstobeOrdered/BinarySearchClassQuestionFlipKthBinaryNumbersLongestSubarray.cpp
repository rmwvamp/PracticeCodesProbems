#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int n, k;
int prefixsum[10100];

void creationprefixsum()
{
    for (int i = 0; i < n; i++)
    {
        /* code */
        if (i >= 1)
            prefixsum[i] = arr[i] + prefixsum[i - 1];
        else
            prefixsum[i] = arr[i];
    }
}

// int check(int x)
// {
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (i > x)
//         {
//             int num_one = prefixsum[i] - prefixsum[i - x - 1];
//             int num_zero = x - num_one;

//             if (num_zero <= k)
//                 return 1;
//         }
//     }

//     return 0;
// }

int check(int x)
{
    for (int i = 0; i < n - x; i++)
    {
        int num_one;
        if (i >= 1) 
        {
            num_one = prefixsum[i + x] - prefixsum[i - 1];
        }
        else if (i == 0)
        {
            num_one = prefixsum[i + x] - prefixsum[i];
        }
        int num_zero = x - num_one;
        cout << "Iteration " << i << endl;
        cout << "Numbers 1: " << num_one << endl;
        cout << "Numbers 0: " << num_zero << endl;
        cout << "Numbers 1+0 is " << num_zero + num_one << " value of x is " << x << endl;
        cout << " K: " << k << endl;
        if (num_zero <= k)
        {
            return 1;
            break;
        }
    }

    return 0;
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    creationprefixsum();
    int lo = 0;
    int hi = n;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        cout << "Lo= " << lo << " Hi " << hi << " mid=" << mid << endl;
        if (check(mid))
        {

            ans = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
        cout << "Next Iteration" << endl
             << "\n";
    }

    cout << ans << endl;
    return 0;
}


/* code 

map<int,int>m;

marr[i]


*/