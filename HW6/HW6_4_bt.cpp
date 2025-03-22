#include <iostream>
using namespace std;
int countAns = 0;

void subset(int x[], int l, int r, int key, int sum)
{
    if (l == r || sum > key)
    {
        if (sum == key)
        {
            countAns++;
        }
        return;
    }
    else
    {
        x[l] = 0;
        subset(x, l + 1, r, key, sum);
        x[l] = 1;
        subset(x, l + 1, r, key, sum + x[l]);
    }
}
int main()
{
    int n, h;
    cin >> n >> h;
    int x[n] = {0};

    subset(x, 0, n, h, 0);
    cout << countAns;
    return 0;
}
