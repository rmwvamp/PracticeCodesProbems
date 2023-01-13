#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int numofdice;
    cin >> numofdice;

    while (t--)
    {

        cout << rand() % (6 * numofdice) + numofdice << endl;
    }

    return 0;
}
