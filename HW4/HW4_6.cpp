#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    sort(array.begin(), array.end());

    vector<int> mergedDigits;
    for (int num : array)
    {
        vector<int> tempDigits;
        while (num > 0)
        {
            tempDigits.push_back(num % 10);
            num /= 10;
        }

        for (int i = tempDigits.size() - 1; i >= 0; --i)
        {
            mergedDigits.push_back(tempDigits[i]);
        }
    }

    for (int i : mergedDigits)
    {
        cout << i;
    }
    cout << endl;

    vector<int> highestFreqDigits;
    int maxFreq = 1;
    for (int i = 0; i < mergedDigits.size(); i++)
    {
        int count = 1;
        for (int j = i + 1; j < mergedDigits.size(); j++)
        {
            if (mergedDigits[i] == mergedDigits[j])
            {
                count++;
            }
            else
            {
                break;
            }
        }

        if (count > maxFreq)
        {
            maxFreq = count;
            highestFreqDigits.clear();
            highestFreqDigits.push_back(mergedDigits[i]);
        }
        else if (count == maxFreq && find(highestFreqDigits.begin(), highestFreqDigits.end(), mergedDigits[i]) == highestFreqDigits.end())
        {
            highestFreqDigits.push_back(mergedDigits[i]);
        }
    }

    sort(highestFreqDigits.begin(), highestFreqDigits.end());
    for (int i : highestFreqDigits)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> uniqueDigits;
    for (int i = 0; i < mergedDigits.size(); ++i)
    {
        if (i == mergedDigits.size() - 1)
        {
            uniqueDigits.push_back(mergedDigits[i]);
            break;
        }
        if (mergedDigits[i] != mergedDigits[i + 1])
        {
            uniqueDigits.push_back(mergedDigits[i]);
        }
    }

    for (int digit : uniqueDigits)
    {
        cout << digit;
    }
    cout << endl;

    return 0;
}
