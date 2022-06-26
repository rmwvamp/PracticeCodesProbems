#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int memo[10100];
    int largestVariance(string s)
    {
        memset(memo, -1, sizeof(memo));
        vector<int> CountofCharacters(26, 0);
        memo[0] = 0;
        CountofCharacters[s[0] - 'a']++;
        for (int i = 1; i < s.size(); i++)
        {
            CountofCharacters[s[i] - 'a']++;
            int MaxValue = INT_MIN;
            int MinValue = INT_MAX;
            // int temp = 0;

            for (int j = 0; j < 26; j++)
            {
                if (CountofCharacters[j] > 0)
                {
                    MaxValue = max(MaxValue, CountofCharacters[j]);

                    MinValue = min(MinValue, CountofCharacters[j]);
                    /* code */
                }
            }

            int MaxVarianceinSubString = MaxValue - MinValue;
            memo[i] = max(memo[i - 1], MaxVarianceinSubString);
        }

        return memo[s.size() - 1];
    }
};

int main()
{

    return 0;
}
