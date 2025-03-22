#include <iostream>
using namespace std;
void printArr(int *arr, int start, int end)
{
    cout << "Array: ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int *arr, int l, int r)
{
    cout << "\nPartitioning array from : " << l << " to " << r << endl;
    int mid = l + (r - l) / 2;
    int pivot = arr[r];

    printArr(arr, l, r);
    cout << "pivot: " << pivot << endl;
    int i = l - 1;
    int j = l;

    for (j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
            printArr(arr, l, r);
        }
    }
    swap(arr[i + 1], arr[j]);
    printArr(arr, l, r);
    return i + 1;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int arr[] = {2, 3, 1, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);

    cout << "\nSorted array is \n";
    printArr(arr, 0, n - 1);
    return 0;
}