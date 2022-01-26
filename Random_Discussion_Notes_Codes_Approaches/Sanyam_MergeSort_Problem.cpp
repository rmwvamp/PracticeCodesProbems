// Time complexity of merge sort is O(nlogn)
#include <iostream>
using namespace std;

void merge1(int arr[], int left, int mid, int right)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int array1[n1];
    int array2[n2];

    for (int i = 0; i < n1; i++)
    {
        array1[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++)
    {
        array2[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (k <= right)
    {
        if ((i < n1) && (j < n2))
        {
            if (array1[i] < array2[j])
            {
                arr[k++] = array1[i++];
            }

            if ((array1[i]) >= (array2[j]))
            {
                arr[k++] = array2[j++];
            }
        }

        else if ((i < n1))
        {
            arr[k++] = array1[i++];
        }

        else
        {
            arr[k++] = array1[j++];
        }
    }
}

void mergesort(int arr[], int l, int r)
{

    if (l >= r)
    {
        return;
    }

    int mid = (l + r) / 2;
    mergesort(arr, l, mid), mergesort(arr, mid + 1, r);
    merge1(arr, l, mid, r);

    return;
}

int main()
{

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/* code

void hey(int& arr[] )







int function()

{

    hey(arr)
    hey(arr)


}

*/