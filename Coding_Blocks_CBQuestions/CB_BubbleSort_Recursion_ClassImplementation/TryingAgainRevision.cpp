#include <bits/stdc++.h>
using namespace std;

int n;
void PermutationofString_rec(int i, char *UserString)
{
    // base case`
    if (UserString[i] == '\0')
    {
        cout << UserString << endl;
        return;
    }

    // recursive case`

    for (int j = i; UserString[j] != '\0'; j++)
    {
        swap(UserString[i], UserString[j]);
        PermutationofString_rec(i + 1, UserString);
        swap(UserString[i], UserString[j]);
    }
}

int main()
{
    char UserString[] = "abc";
    n = sizeof(UserString) / sizeof(char);
    PermutationofString_rec(0, UserString);
    return 0;
}
