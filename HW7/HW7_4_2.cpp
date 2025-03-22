#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int m;
    cin >> m;

    while (m--)
    {
        int n, k;
        cin >> n;

        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> B[i];
        }
        cin >> k;

        sort(A.begin(), A.end());
        sort(B.rbegin(), B.rend());

        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (A[i] + B[i] < k)
            {
                valid = false;
            }
        }

        cout << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}
