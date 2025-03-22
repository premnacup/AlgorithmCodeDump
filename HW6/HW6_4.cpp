#include <iostream>
#include <vector>
using namespace std;

void print_sol(int x[], int n)
{
    int empty = 1;
    for (int i = n; i >= 1; i--)
    {
        if (x[i] == 1)
        {
            cout << (n - i) + 1;
            empty = 0;
        }
    }
    if (empty)
    {
        cout << "0";
    }
    cout << endl;
}

void subset(int x[], int l, int n, int &count)
{
    if (l > n)
    {
        print_sol(x, n);
        count++;
        return;
    }
    x[l] = 0;
    subset(x, l + 1, n, count);
    x[l] = 1;
    subset(x, l + 1, n, count);
}

int main()
{
    int n;
    cin >> n;

    int x[n + 1] = {0};
    int count = 0;

    subset(x, 1, n, count);
    cout << count << endl;

    return 0;
}