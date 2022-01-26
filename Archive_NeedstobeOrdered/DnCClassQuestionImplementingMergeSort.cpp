#include <bits/stdc++.h>
using namespace std;
int main()
{
    int asize;
    int bsize;
    cin >> asize >> bsize;
    vector<int> A;
    vector<int> B;
    vector<int> C;
    for (int i = 0; i < asize; i++)
    {
        int x;
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < bsize; i++)
    {
        int x;
        cin >> x;
        B.push_back(x);
    }
    int i = 0, j = 0;
    for (int count = 0; i < A.size() && j < B.size(); count++)
    {
        /* code */
        if (A[i] > B[j])
        {
            /* code */
            C.push_back(B[j]);
            j++;
            // k++;
        }
        else
        {
            C.push_back(A[i]);
            i++;
        }
    }

    for (int count = 0; i < A.size(); count++)
    {
        /* code */
        C.push_back(A[i]);
        i++;
    }
    for (int count = 0; j < B.size(); count++)
    {
        /* code */
        C.push_back(B[j]);
        j++;
    }
    for (int row = 0; row < C.size(); row++)
    {
        cout << C[row] << " ";
    }

    return 0;
}