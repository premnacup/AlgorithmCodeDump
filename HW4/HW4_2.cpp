#include <iostream>
using namespace std;
void quicksort(int, int, int *);
int partition(int, int, int *);

int main()
{
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    int arr[] = {1, 5, 10, 4, 8, 2, 6, 9, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    quicksort(0, n - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

void quicksort(int low, int high, int *arr)
{
    if (low >= high)
    {
        return;
    }
    cout << "start:" << low << " end:" << high << endl;
    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int partitionIndex = partition(low, high, arr);
    quicksort(low, partitionIndex - 1, arr);
    quicksort(partitionIndex + 1, high, arr);
}
int partition(int start, int end, int *arr)
{
    int pivot = arr[start];
    int forward = start;
    int backward = end + 1;
    while (forward < backward)
    {
        do
        {
            forward++;
        } while (arr[forward] < pivot);
        do
        {
            backward--;
        } while (arr[backward] > pivot);

        swap(arr[forward], arr[backward]);
        cout << "Swapping elements: " << arr[forward] << " and " << arr[backward] << endl;
        for (int i = start; i <= end; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    swap(arr[forward], arr[backward]);
    swap(arr[start], arr[backward]);

    return backward;
}
