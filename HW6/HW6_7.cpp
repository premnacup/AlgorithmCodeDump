#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int min_dif = INT_MAX;

void solve(int arr[], int n)
{
    int sum_older = 0;
    int sum_younger = 0;
    for (int i = 0; i < n; i++)
    {
        sum_older += arr[i];
    }
    for (int j = n; j < n * 2; j++)
    {
        sum_younger += arr[j];
    }
    int dif = abs(sum_older - sum_younger);
    min_dif = min(min_dif, dif);
}

void permute(int arr[], int start, int end, int n)
{
    if (start == end)
    {
        solve(arr, n);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(arr[start], arr[i]);
        permute(arr, start + 1, end, n);
        swap(arr[start], arr[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n * 2];
    for (int i = 0; i < n * 2; i++)
    {
        cin >> arr[i];
    }
    permute(arr, 0, (n * 2) - 1, n);
    cout << min_dif << endl;
}