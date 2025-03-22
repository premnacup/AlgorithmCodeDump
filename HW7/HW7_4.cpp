#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int n, vector<int> &gifts)
{
    int sumA = 0, sumB = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (sumA < sumB)
        {
            sumA += gifts[i];
        }

        else
        {
            sumB += gifts[i];
        }
    }
    return abs(sumA - sumB);
}

int main()
{
    int n;
    cin >> n;

    vector<int> gifts(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> gifts[i];

    sort(gifts.begin(), gifts.end(), greater<int>());

    cout << solve(n, gifts);
    return 0;
}
