#include <bits/stdc++.h>
using namespace std;

vector<int> frequency(1001000, 0);
int countDistinct = 0;
void insert(int x)
{
    frequency[x]++;
    if (frequency[x] == 1)
    {
        countDistinct++;
    }
}

void remove(int x)
{
    frequency[x]--;
    if (frequency[x] == 0)
    {
        countDistinct--;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int head = -1, tail = 0, ans = 0;
    while (tail < n)
    {
        while (head + 1 < n && (((countDistinct <= k && frequency[v[head + 1]] != 0) || (countDistinct < k && frequency[v[head + 1]] == 0))))
        {
            head++;
            insert(v[head]);
        }
        ans = max(ans, head - tail + 1);
        if (head >= tail)
        {
            remove(v[tail]);
            tail++;
        }
        else
        {
            tail++;
            head = tail - 1;
        }
    }
    cout << ans;
}