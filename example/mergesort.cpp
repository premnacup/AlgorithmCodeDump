#include <bits/stdc++.h>
using namespace std;

/**
 * Merge two sorted subarrays into one sorted subarray
 * @param arr the array to be sorted
 * @param l the starting index of the first subarray
 * @param m the ending index of the first subarray
 * @param r the ending index of the second subarray
 */
void merge(int arr[], int l, int m, int r)
{
    int left = m - l + 1;
    int right = r - m;
    int arrL[left];
    int arrR[right];

    // copy elements from arr[] to arrL[] and arrR[]
    for (int i = 0; i < left; i++)
    {
        arrL[i] = arr[l + i];
    }

    for (int i = 0; i < right; i++)
    {
        arrR[i] = arr[m + 1 + i];
    }

    int i, j, k;
    for (i = l, j = 0, k = 0; j < left && k < right; i++)
    {
        if (arrL[j] > arrR[k])
        {
            arr[i] = arrR[k];
            k++;
        }
        else
        {
            arr[i] = arrL[j];
            j++;
        }
    }

    // copy the remaining elements of arrL[] to arr[]
    for (int iter = j; iter < left; iter++)
    {
        arr[i] = arrL[iter];
        i++;
    }

    // copy the remaining elements of arrR[] to arr[]
    for (int iter = k; iter < right; iter++)
    {
        arr[i] = arrR[iter];
        i++;
    }
}

void mergeSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
    int arr[] = {9, 2, 3, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);

    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}