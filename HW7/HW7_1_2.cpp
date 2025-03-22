#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> weights)
{
    int sumA = 0, sumB = 0;
    for (int w = 0; w < weights.size(); w++)
    {
        if (sumA < sumB)
        {
            sumA += weights[w];
        }
        else
        {
            sumB += weights[w];
        }
    }

    return abs(sumA - sumB);
}

int main()
{
    int n;
    cin >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end(), greater<int>());

    cout << solve(weights) << endl;
    return 0;
}