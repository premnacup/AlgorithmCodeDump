#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x);
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    cout << "Enter the key to be searched: " << endl;
    cin >> key;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
    {
        cout << "Element is not present in array" << endl;
    }
    else
    {
        cout << "Element is present at index " << result << endl;
    }
    return 0;
}
int binarySearch(int arr[], int l, int r, int x)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        if (arr[mid] > x)
        {
            return binarySearch(arr, l, mid - 1, x);
        }
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}