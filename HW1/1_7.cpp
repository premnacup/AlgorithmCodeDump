#include <iostream>
using namespace std;

int main()
{
    int n;
    int search;

    cin >> n;
    cin >> search;
    int arr[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool found = false;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == search)
            {
                found = true;
                cout << arr[i] << " " << arr[j] << endl;
            }
        }
    }
    cout << (found ? "" : "-1");
}