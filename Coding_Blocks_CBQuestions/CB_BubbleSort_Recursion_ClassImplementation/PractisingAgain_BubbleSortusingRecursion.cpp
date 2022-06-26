#include <bits/stdc++.h>
using namespace std;

void BubbleSort_Recursion(int *arr, int i, int n)
{
    bool isSorted = true;
    if (i == n)
    {
        return;
    }

    // Recursive Case
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            isSorted = false;

            swap(arr[j], arr[j + 1]);
        }
    }
    if (isSorted)
        return;
    BubbleSort_Recursion(arr, i + 1, n);
}

void BubbleSort_Recursion_WithoutBestCase(int *arr, int i, int n)
{
    // if (isSorted && i > 0)
    // {
    //     return;
    // }
    if (i == n)
    {
        return;
    }

    // Recursive Case
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {

            swap(arr[j], arr[j + 1]);
        }
    }
    BubbleSort_Recursion_WithoutBestCase(arr, i + 1, n);
}

void BubbleSort_withoutusingLoop(int i, int j, int n, int *arr)
{
    if (i == n)
    {
        return;
    }

    if (j == n - 1)
    {
        BubbleSort_withoutusingLoop(i + 1, 0, n, arr);
    }
    else
    {

        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
        BubbleSort_withoutusingLoop(i, j + 1, n, arr);
    }

    // Recursive Case
}

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int arr1[5] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);
    // BubbleSort_Recursion_WithoutBestCase(arr, 0, n);
    // for (int x : arr)
    // {
    //     cout << x << " ";
    // }
    // cout << endl;
    BubbleSort_withoutusingLoop(0, 0, n, arr);
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}