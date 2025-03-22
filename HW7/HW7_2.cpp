#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

double solve(vector<double> &input, int n)
{
    vector<double> mem(n);
    mem[0] = input[0];
    double ans = mem[0];

    for (int i = 1; i < n; i++)
    {
        mem[i] = mem[i - 1] + input[i];
        ans += mem[i];
    }

    return ans / n;
}

int main()
{
    int n;
    cin >> n;
    vector<double> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    cout << fixed << setprecision(2) << solve(input, n);
}
