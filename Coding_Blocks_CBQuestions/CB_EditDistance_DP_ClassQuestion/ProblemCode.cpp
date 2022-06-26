// EditDistance.cpp
#include <bits/stdc++.h>
using namespace std;

int EditDistance(char *s1, char *s2, int i, int j, int dp[][100])
{
    // base case
    // if (i < 0 || j < 0)
    // {
    //     return 0;
    // }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == 0)
    {
        return j;
    }
    if (j == 0)
    {
        return i;
    }
    // recursive case
    if (s1[i - 1] == s2[j - 1])
    {
        // ignore
        return dp[i][j] = EditDistance(s1, s2, i - 1, j - 1, dp);
    }
    else
    {
        int op1 = EditDistance(s1, s2, i - 1, j - 1, dp); // Replace
        int op2 = EditDistance(s1, s2, i, j - 1, dp);     // Insert
        int op3 = EditDistance(s1, s2, i - 1, j, dp);     // Delete
        return dp[i][j] = min(op1, min(op2, op3)) + 1;
    }
}

int main()
{

    // char a[1000], b[1000];
    int dp[100][100];
    memset(dp, -1, sizeof(dp));
    // cin >> a >> b;
    char a[] = "abcd";
    char b[] = "def";

    int i = strlen(a);
    int j = strlen(b);

    cout << EditDistance(a, b, i, j, dp);

    cout << endl;
    return 0;
}