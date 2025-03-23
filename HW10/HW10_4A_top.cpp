#include <iostream>
#include <vector>
using namespace std;

long long F_topdown(int n, int k, vector<vector<long long>> &memo)
{

    if (k == 0)
    {
        return 1;
    }
    if (k == 1)
    {
        return 1;
    }
    if (n == k)
    {
        return 1;
    }
    if (memo[n][k] != -1)
    {
        return memo[n][k];
    }

    if (n >= k)
    {
        memo[n][k] = F_topdown(n - 1, k, memo) + F_topdown(n - 1, k - 2, memo);
    }

    return memo[n][k];
}

int main()
{
    int n = 6, k = 4;

    vector<vector<long long>> memo(n + 1, vector<long long>(k + 1, -1));

    cout << "F(" << n << ", " << k << ") = " << F_topdown(n, k, memo) << endl;

    return 0;
}