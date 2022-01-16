#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int k;
        cin >> k;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int C[n];

        int ans = 0;
        C[0] = A[0];
        //  cout<<C[0]<<" ";
        for (int i = 1; i < n; i++)
        {
            C[i] = C[i - 1];
            if (A[i] == 1)
            {
                C[i]++;
            }
            //   cout<<C[i]<<" "; prefix sum created
        }
        if ((n - C[n - 1]) <= k) // no of zeroes in comparision
        {
            cout << n;
        }
        else
        {
            int l = k, e = C[n - 1] + k, mid; // since our max value is now going to be n-(no.of zeroes-k)
            while (l <= e)
            {
                mid = (l + e) / 2;
                int i;
                for (i = 0; i < n - mid + 1; i++)
                {
                    int j = i + mid - 1;
                    // C[j]-C[i]=no.of ones and i need to check whether number of zeroes is less than k or not
                    // implies mid-(no. of ones)<=k
                    if (i == 0)
                    {
                        if ((mid - C[j]) == k)
                        {
                            ans = mid;
                            break;
                        }
                    }
                    else if ((mid - C[j] + C[i]) == k)
                    {
                        ans = mid;
                        break;
                    }
                }
                if (i == (n - mid))
                {
                    e = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            cout << ans;
        }
    }
    return 0;
}
