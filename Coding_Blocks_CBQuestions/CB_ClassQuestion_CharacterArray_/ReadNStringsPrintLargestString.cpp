#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s[n];
    int ans = 0;
    string AnswerString;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> s[i];
        ans = max(ans, s[i].length());
        if (ans == s[i].length())
        {
            AnswerString = s[i];
        }
    }
    cout << ans << endl;

    return 0;
}