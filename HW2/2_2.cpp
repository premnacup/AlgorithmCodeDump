#include <iostream>
#include <climits>
#include <algorithm>
int solve(int[], int, int);
using namespace std;
int main()
{
    int n, search;
    cin >> n >> search;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, search, n);
}

int solve(int arr[], int key, int n)
{
    sort(arr, arr + n);
    int min = INT_MAX;
    int left = 0, right = n - 1, check;
    while (left <= right)
    {
        check = arr[left] + arr[right];
        if (check == key)
        {
            min = ((arr[right] - arr[left]) < min) ? arr[right] - arr[left] : min;
        }
        if (check < key)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return min;
}