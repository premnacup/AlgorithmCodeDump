#include <iostream>
#include <algorithm>
using namespace std;
int countAns = 0;

bool isPrime(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isValidCircle(int x[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (!isPrime(x[i] + x[i + 1]))
        {
            return false;
        }
    }
    if (!isPrime(x[1] + x[n]))
    {
        return false;
    }
    return true;
}

void permute(int x[], int start, int end)
{
    if (start == end)
    {
        if (isValidCircle(x, end))
        {
            countAns++;
        }
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(x[start], x[i]);
        permute(x, start + 1, end);
        swap(x[start], x[i]);
    }
}

int main()
{
    int n;
    cin >> n;
    int x[n + 1];
    for (int i = 1; i <= n; i++)
    {
        x[i] = i;
    }

    permute(x, 2, n);
    cout << countAns << endl;

    return 0;
}