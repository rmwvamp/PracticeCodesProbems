#include <bits/stdc++.h>
using namespace std;

int rec(int l, int r, int dp[110][110])
{
    return dp[l][r] = l * r-dp[l-];
}
int main()
{
    int dp[110][110];
    int n = 5;
    rec(0, n - 1, dp);
    return 0;
}