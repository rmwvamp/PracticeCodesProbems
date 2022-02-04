#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixMultiplication(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> ans(2, vector<int>(2));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<int>> binaryExpo(vector<vector<int>> a, int b)
{
    vector<vector<int>> prod = a;
    vector<vector<int>> ans{{1, 0}, {0, 1}};
    while (b)
    {
        if (b & 1)
        {
            ans = matrixMultiplication(ans, prod);
        }
        b /= 2;
        prod = matrixMultiplication(prod, prod);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> fibMatrix{{1, 1}, {1, 0}};
    vector<vector<int>> ans = binaryExpo(fibMatrix, n);
    // for(int i = 0 ; i < 2 ; i++)
    // {
    //     for(int j = 0 ; j < 2 ; j++)
    //     {
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << ans[0][1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}