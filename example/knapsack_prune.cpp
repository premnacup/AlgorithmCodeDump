#include <bits/stdc++.h>
using namespace std;
int countRecur = 0;
int maxValue = -1;
int k = 18;
int ans[4];

void subset1(int x[], int arr[], int arr2[], int l, int r, int sumWeight = 0, int sumValue = 0)
{
    if (l == r)
    {
        countRecur++;
        if (sumWeight <= k && sumValue > maxValue)
        {
            maxValue = sumValue;
            for (int i = 0; i < r; i++)
            {
                ans[i] = x[i + 1];
            }
        }
        return;
    }
    if (sumWeight > k)
    {
        return;
    }

    x[l + 1] = 1;
    sumWeight += arr[l];
    sumValue += arr2[l];
    subset1(x, arr, arr2, l + 1, r, sumWeight, sumValue);

    x[l + 1] = 0;
    sumWeight -= arr[l];
    sumValue -= arr2[l];
    subset1(x, arr, arr2, l + 1, r, sumWeight, sumValue);
}
int main()
{
    int weight[] = {12, 5, 4, 2};
    int value[] = {8, 7, 4, 2};

    int n = sizeof(weight) / sizeof(weight[0]);
    int x[n + 1] = {0};

    subset1(x, weight, value, 0, n);

    cout << "Weight: ";
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1)
        {
            cout << weight[i] << " ";
        }
    }
    cout << endl;
    cout << "Value: ";
    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 1)
        {
            cout << value[i] << " ";
        }
    }
    cout << endl;
    cout << countRecur << endl;
    return 0;
}
