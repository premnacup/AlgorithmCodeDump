#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = INT_MIN;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i; j < n; j++)
        {
            int sum = 0;

            for (size_t k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            if (sum > max)
            {
                max = sum;
            }
        }
    }
    cout << max;
}