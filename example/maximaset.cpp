#include <bits/stdc++.h>
using namespace std;
class Point
{
public:
    int x, y;
    bool active = true;

    void inputCoordinate()
    {
        cin >> x >> y;
    }

    void printActive() const
    {
        if (active)
        {
            cout << "(" << x << ", " << y << ") ";
        }
    }
};

void merge(Point arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k;
    Point L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    i = l;
    j = 0;
    k = 0;

    for (; j < n1 && k < n2; i++)
    {
        if (L[j].x < R[k].x)
        {
            arr[i] = L[j];
            j++;
        }
        else
        {
            arr[i] = R[k];
            k++;
        }
    }

    for (; j < n1; j++, i++)
    {
        arr[i] = L[j];
    }

    for (; k < n2; k++, i++)
    {
        arr[i] = R[k];
    }
}

void mergeSort(Point arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void solve(Point arr[], int l, int m, int r)
{
    Point maxR = arr[m + 1];
    for (int i = l; i <= m; i++)
    {
        if (arr[i].y < maxR.y)
        {
            arr[i].active = false;
        }
    }
}

void divide(Point arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        divide(arr, l, m);
        divide(arr, m + 1, r);
        solve(arr, l, m, r);
    }
}

int main()
{
    int n;
    cin >> n;
    Point arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].inputCoordinate();
    }

    mergeSort(arr, 0, n - 1);
    divide(arr, 0, n - 1);
    cout << "Maxima set: " << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].printActive();
    }
    return 0;
}
