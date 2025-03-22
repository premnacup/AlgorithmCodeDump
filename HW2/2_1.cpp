#include <iostream>
using namespace std;
int inter_search(int[], int, int, int);
int main()
{
    int n, search;
    cin >> n >> search;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    inter_search(arr, 0, n - 1, search);
}

int inter_search(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (key - arr[left]) * (right - left) / (arr[right] - arr[left]);
        cout << mid << " ";
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return inter_search(arr, mid + 1, right, key);
        }
        else
        {
            return inter_search(arr, left, mid - 1, key);
        }
    }

    return -1;
}