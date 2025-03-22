#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
void search(int[], int, int, int);
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m, k;
    cin >> m >> k;

    search(arr, m, k, n);
    return 0;
}

void search(int arr[], int m, int k, int n)
{
    sort(arr, arr + n);
    int i = 0;

    while (i < n && arr[i] < m - 1)
    {
        i++;
    }
    int left = i - 1;
    int right = i;
    while (right - left <= k)
    {
        cout << left << " " << right << endl;
        if (left < 0)
        {
            right++;
        }
        else if (right > n)
        {
            left--;
        }
        else if (abs(arr[left] - m) <= abs(arr[right] - m))
        {
            left--;
        }
        else
        {
            right++;
        }
    }
}