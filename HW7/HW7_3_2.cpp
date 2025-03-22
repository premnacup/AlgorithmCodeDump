#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxChocolates(vector<int> &chocolates)
{
    int n = chocolates.size();
    if (n == 1)
    {
        return chocolates[0];
    }

    vector<int> dp(n, 0);
    dp[0] = chocolates[0];
    dp[1] = max(chocolates[0], chocolates[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], chocolates[i] + dp[i - 2]);
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++)
    {
        cin >> chocolates[i];
    }

    cout << maxChocolates(chocolates) << endl;
    return 0;
}
