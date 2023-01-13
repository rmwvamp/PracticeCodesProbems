
#include <bits/stdc++.h>
using namespace std;

bool solve(string n, int length)
{
    int bucketarr[10] = {0};
    if (length < 3)
    {
        if (stoi(n) % 8 == 0)
            return true;

        reverse(n.begin(), n.end());
        if (stoi(n) % 8 == 0)
            return true;
        return false;
    }

    for (int i = 0; i < length; i++)
        bucketarr[n[i] - '0']++;

    for (int i = 104; i < 1000; i += 8)
    {
        int hashedarr[10] = {0};
        int dup = i;

        hashedarr[dup % 10]++;
        dup /= 10;
        hashedarr[dup % 10]++;
        dup /= 10;
        hashedarr[dup % 10]++;

        dup = i;
        if (hashedarr[dup % 10] > bucketarr[dup % 10])
            continue;
        dup /= 10;

        if (hashedarr[dup % 10] > bucketarr[dup % 10])
            continue;
        dup /= 10;

        if (hashedarr[dup % 10] > bucketarr[dup % 10])
            continue;

        return true;
    }

    return false;
}

// Driver Code
int main()
{
    string number = "31462708";
    int l = number.length();

    if (solve(number, l))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
