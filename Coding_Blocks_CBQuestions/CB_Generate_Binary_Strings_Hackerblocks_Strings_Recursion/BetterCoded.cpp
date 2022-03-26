#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

void rec_secondtry(string &input, char *output, int i, int j)
{
    // base case
    if (input[i] == '\0')
    {
        output[j] = '\0';
        cout << output << " ";
        return;
    }
    if (input[i] == '?')
    {
        output[j] = '0';
        rec_secondtry(input, output, i + 1, j + 1);
        output[j] = '1';
        rec_secondtry(input, output, i + 1, j + 1);
    }
    else
    {
        output[j] = input[i];
        rec_secondtry(input, output, i + 1, j + 1);
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;
        // char input[] = str;
        char output[100];
        rec_secondtry(input, output, 0, 0);
        cout << endl;
    }

    return 0;
}
