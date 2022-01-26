#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans;
    for (int i = 0; i < 3; i++)
    {
        /* code */
        vector<int> temp;
        for (int j = 12; j < 98; j++)
        {
            /* code */
            temp.push_back(j);
        }
        ans.push_back(temp);
    }

    return 0;
}