#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++)
    {
        cin >> segments[i].first >> segments[i].second;
    }

    int xa, xb;
    cin >> xa >> xb;

    vector<pair<int, int>> relevant;
    for (int i = 0; i < n; i++)
    {
        if (segments[i].second < xa || segments[i].first > xb)
            continue;
        relevant.push_back({max(xa, segments[i].first), min(xb, segments[i].second)});
    }

    sort(relevant.begin(), relevant.end());

    vector<pair<int, int>> result;
    int current = xa;

    while (current < xb)
    {
        int best_end = current;
        pair<int, int> best_segment = {-1, -1};

        for (int i = 0; i < relevant.size(); i++)
        {
            if (relevant[i].first <= current && relevant[i].second > best_end)
            {
                best_end = relevant[i].second;
                best_segment = relevant[i];
            }
        }

        if (best_segment.first == -1)
        {
            cout << "-1" << endl;
            return 0;
        }

        result.push_back(best_segment);
        current = best_end;

        if (current >= xb)
            break;
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
