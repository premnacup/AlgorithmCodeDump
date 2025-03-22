#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int solve(vector<pair<float, float>> schedule, int n)
{
    int count_ = 0;
    for (int i = 0; i < n; i++)
    {
        if (schedule[i + 1].first < schedule[i].second)
        {
            count_++;
        }
        else
        {
            count_--;
        }
    }
    return count_;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<float, float>> schedule(n);
    for (int i = 0; i < n; i++)
    {
        cin >> schedule[i].first >> schedule[i].second;
    }
    sort(schedule.begin(), schedule.end());
    cout << solve(schedule, n);
}
