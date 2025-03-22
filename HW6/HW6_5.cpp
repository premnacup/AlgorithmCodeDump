#include <iostream>
#include <algorithm>
using namespace std;

int maxv = 0;

void subset(int arr[], int l, int r, int sum)
{
    if (l >= r)
    {
        maxv = max(maxv, sum);
        return;
    }
    subset(arr, l + 2, r, sum + arr[l]);
    subset(arr, l + 1, r, sum);
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

    subset(arr, 0, n, 0);
    cout << maxv << endl;
}