#include <iostream>
using namespace std;

int minSquares(int m, int n)
{
    if (m == n)
    {
        return 1;
    }
    if (m < n)
    {
        swap(m, n);
    }
    return 1 + minSquares(m - n, n);
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << minSquares(m, n) << endl;
    return 0;
}