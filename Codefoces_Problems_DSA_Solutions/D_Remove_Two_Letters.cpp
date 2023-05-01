#include <iostream>
using namespace std;
bool check(int num)
{
    int r = 0;
    int n = num;
    int x = num;
    while (num > 0)
    {
        x %= 10;
        r += x * x * x;
        num /= 10;
    }
    return n == r;
}
int fun(int p = 10, int q = 20)
{
    int s = 0;
    for (int i = p; i < q + 1; i++)
    {
        if (check(i))
        {
            s += 1;
        }
    }
    return s;
}