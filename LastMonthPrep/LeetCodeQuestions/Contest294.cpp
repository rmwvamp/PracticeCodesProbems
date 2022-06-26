#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int minimumLines(vector<vector<int>> &stockPrices)
//     {
//         int n = stockPrices.size();
//         for (int i = 1; i < n - 1; i++)
//         {
//             int j = i + 1;
//             int m = (stockPrices[i][1] - stockPrices[j][1]) / (stockPrices[i][0] - stockPrices[j][0]);
//             while (j < n && (stockPrices[j][1] - stockPrjces[i][1]) / (stockPrices[i][0] - stockPrices[i - 1][0]))
//             {
//                 cnt += event[j].second;
//                 j++;
//             }
//             i = j - 1;
//             if (i != (event.size() - 1))
//             {

//                 ll SegmentLength = event[i + 1].first - event[i].first;
//                 LenCovered[cnt] += SegmentLength;
//             }
//         }
//     }
// };

class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[0] < b[0];
    }
    int minimumLines(vector<vector<int>> &stockPrices)
    {
        sort(stockPrices.begin(), stockPrices.end(), cmp);
        vector<double> Slope(stockPrices.size());
        int n = stockPrices.size();
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            double m = (stockPrices[i][1] - stockPrices[j][1]) * 1.0 / (stockPrices[i][0] - stockPrices[j][0]) * 1.0;
            Slope[i] = m;
        }
        int cnt = 0;
        for (int i = 0; i < n - 1; i++)
        {
            cnt++;
            int j = i;
            while (j < n - 1 && Slope[i] == Slope[j])
            {
                j++;
            }
            j--;
            i = j;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}
