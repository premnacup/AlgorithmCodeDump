#include <bits/stdc++.h>
using namespace std;
int countRecur = 0;
int key = 12;

void print_sol(int x[], int arr[], int n)
{
    int sum = 0;
    cout << "Sequence: ";
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
        if (x[i] == 1)
        {
            sum += arr[i - 1];
        }
    }
    cout << endl;

    cout << "Value: ";
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 1)
        {
            cout << arr[i - 1] << " ";
        }
    }
    cout << endl;
    cout << "Sum : " << sum << endl;
}

void subset1(int x[], int arr[], int l, int r, int sum)
{
    if (sum > key || l == r)
    {
        countRecur++;
        if (sum == key)
        {
            countRecur++;
            print_sol(x, arr, r);
        }
        return;
    }

    x[l + 1] = 1;
    subset1(x, arr, l + 1, r, sum + arr[l]);

    x[l + 1] = 0;
    subset1(x, arr, l + 1, r, sum);
}

int main()
{
    int arr[] = {25, 10, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x[n + 1];

    subset1(x, arr, 0, n, 0);
    cout << countRecur << endl;
    return 0;
}
