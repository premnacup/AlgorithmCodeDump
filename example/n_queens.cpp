#include <cmath>
#include <iostream>

using namespace std;
int n = 4, x[4];
int countRecur = 0;

bool checkOverlap(int x[], int k)
{
    for (int j = 1; j < k; j++)
    {
        for (int p = 0; p < j; p++)
        {
            if (abs(p - j) == abs(x[p] - x[j]) || (x[j] == x[p]))
            {
                return false;
            }
        }
    }
    return true;
}

void n_queens(int k)
{
    if (k == n)
    {
        countRecur++;
        if (checkOverlap(x, k))
        {
            for (int i = 0; i < k; i++)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        for (int row = 0; row < n; row++)
        {
            x[k] = row;
            if (!checkOverlap(x, k))
            {
                return;
            }
            n_queens(k + 1);
        }
    }
}

int main()
{
    n_queens(0);
    cout << countRecur;
    return 0;
}
