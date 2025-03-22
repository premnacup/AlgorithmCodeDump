#include <iostream>
using namespace std;
int count = 0;

void print_sol(int x[], int k)
{
    for (int i = 1; i <= k; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void subset(int x[], int used[], int l, int n, int k)
{
    if (l > k)
    {
        print_sol(x, k);
        count++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            x[l] = i;
            used[i] = 1;
            subset(x, used, l + 1, n, k);
            used[i] = 0;
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int x[k + 1];
    int used[n + 1] = {0};
    subset(x, used, 1, n, k);
    cout << count << endl;
    return 0;
}