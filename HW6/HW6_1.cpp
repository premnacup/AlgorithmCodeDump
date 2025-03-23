#include <bits/stdc++.h>
using namespace std;

void printAns(char x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void rightRotate(char x[], int i, int j)
{
    int temp = x[j];
    for (int k = j; k > i; k--)
    {
        x[k] = x[k - 1];
    }
    x[i] = temp;
}

void leftRotate(char x[], int i, int j)
{
    int temp = x[i];
    for (int k = i; k < j; k++)
    {
        x[k] = x[k + 1];
    }
    x[j] = temp;
}

void permute(char x[], int start, int end)
{
    if (start == end)
    {
        printAns(x, end);
        return;
    }

    permute(x, start + 1, end);

    for (int j = start + 1; j < end; j++)
    {
        rightRotate(x, start, j);
        permute(x, start + 1, end);
        leftRotate(x, start, j);
    }
}

int main()
{
    int n;
    cin >> n;
    char x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    permute(x, 0, n);

    return 0;
}
