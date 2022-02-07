#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    // vector<int> myvector(3);
    // myvector[1].push_back(8);
    // // myvector.push_back(2);
    // // myvector.push_back(3);
    // // myvector.push_back(4);
    // // myvector.push_back(5);
    // for (auto num : myvector)
    // {
    //     cout << num << endl;
    //     }
    // int array[29];

    vector<int> arr[2] = {{1, 2, 28282},
                          {1, 282828, 2}};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}