#include <iostream>
#include <algorithm>
#include <vector>
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
    int pivot;
    vector<int> mo3 = {arr[l], arr[mid], arr[r]};
    sort(mo3.begin(), mo3.end());
    arr[l] = mo3[0];
    arr[mid] = mo3[2];
    arr[r] = mo3[1];
    pivot = mo3[1];

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
int quickSelect(int *arr, int low, int high, int k)
{
    if (low == high)
        return arr[low];
    int p = partition(arr, low, high);
    if (k - 1 == p - low)
        return arr[p];
    else if (k - 1 < p - low)
        return quickSelect(arr, low, p - 1, k);
    else
    {
        k = (k - p - low) - 1;
        return quickSelect(arr, p + 1, high, k);
    }
}
int main()
{
    int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << quickSelect(arr, 0, n - 1, k);
    return 0;
}
