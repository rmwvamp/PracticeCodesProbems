#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int goodPaths(int curr, vector<int> &value, vector<vector<int>> &adjacencyList, map<int, int> &frequency, int currLength = 0, int maxFreq = 0, int parent = -1)
{
    frequency[value[curr]]++;
    currLength++;
    if (frequency[value[curr]] > maxFreq)
        maxFreq = frequency[value[curr]];
    int ans = 0;
    if (maxFreq >= (currLength + 1) / 2)
        ans++;
    for (int i = 0; i < adjacencyList[curr].size(); i++)
    {
        if (adjacencyList[curr][i] != parent)
            ans += goodPaths(adjacencyList[curr][i], value, adjacencyList, frequency, currLength, maxFreq, curr);
    }
    return ans;
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> value(n, 0);
        for (int i = 0; i < n; i++)
            cin >> value[i];
        vector<vector<int>> adjacencyList(n, vector<int>(0, 0));
        for (int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            adjacencyList[a - 1].push_back(b - 1);
            adjacencyList[b - 1].push_back(a - 1);
        }
        map<int, int> frequency;
        cout << goodPaths(0, value, adjacencyList, frequency) << endl;
    }
    return 0;
}