#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> genPrimeNum(int n)
{
    vector<int> primeNums;
    for (size_t i = 1; i <= n; i++)
    {
        if (isPrime(i))
        {
            primeNums.push_back(i);
        }
    }

    return primeNums;
}

void shellSort(int arr[], int n)
{
    vector<int> primeNums = genPrimeNum(n);
    int index = primeNums.size() - 1;
    for (int gap = primeNums[index]; index >= 0; gap = primeNums[--index])
    {
        for (int iter = 0; iter < n; iter++)
        {
            cout << arr[iter] << " ";
        }
        cout << endl;

        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    int arr[6] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    shellSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
