#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n, maxW;
    cin >> n >> maxW;
    pair<double, double> item[n];
    // price, weight
    pair<double, double> clonedItem[n];
    // weight, calc ratio
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].second;
        clonedItem[i].first = item[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> item[i].first;
    }

    sort(item, item + n, [](auto &a, auto &b)
         { return a.second / a.first < b.second / b.first; });

    double tempSum = 0;
    vector<double> select(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (item[i].second + tempSum < maxW)
        {
            select[i] = 1.00;
            for (int iter = 0; iter < n; iter++)
            {
                if (item[i].second == clonedItem[iter].first)
                {
                    clonedItem[iter].second = 1.00;
                    break;
                }
            }
            tempSum += item[i].second;
        }
        else
        {
            double scaler = (maxW - tempSum) / item[i].second;
            select[i] = scaler;
            for (int iter = 0; iter < n; iter++)
            {
                if (item[i].second == clonedItem[iter].first)
                {
                    clonedItem[iter].second = scaler;
                    break;
                }
            }
            tempSum += item[i].second * scaler;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << fixed;
        cout.precision(2);
        cout << clonedItem[i].second << " ";
    }
    cout << endl;
    tempSum = 0;
    for (int i = 0; i < n; i++)
    {
        tempSum += select[i] * item[i].first;
    }
    cout << tempSum << endl;
    return 0;
}