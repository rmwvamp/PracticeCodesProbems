#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10;
    // cin >> n;
    vector<int> count(32, 0);
    vector<int> vi{0b0111, 0b0111, 0b0111, 0b0111, 0b0111, 0b0111, 0b0111, 0b0111, 0b0111, 0b0111};
    for (int i = 0; i < n; i++) /* Counting the number of 1's and 0's in O(n), where n is the number of elements */
    {
        for (int j = 0; j < 31; j++)
        {

            if (vi[i] & (1LL >> j))
            {
                count[j]++;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 31; i++)
    {
        sum += pow(2, i) * ((n - count[i]) * count[i] + 1LL * count[i] * count[i - 1] / 2);
        /* Or we could also do the following nC2 - # 0f's C 2 */
    }
    cout << sum << endl;

    return 0;
}