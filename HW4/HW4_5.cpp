#include <iostream>
#include <vector>
using namespace std;
vector<int> unionList(int[], int[], int);
vector<int> intersectList(int[], int[], int);

int main()
{
    int n;
    cin >> n;
    int A[n], B[n];

    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (size_t i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<int> intersectVal = intersectList(A, B, n);
    vector<int> unionVal = unionList(A, B, n);

    for (size_t i = 0; i < intersectVal.size(); i++)
    {
        cout << intersectVal[i] << " ";
    }

    std::cout << std::endl;

    for (size_t i = 0; i < unionVal.size(); i++)
    {
        cout << unionVal[i] << " ";
    }

    return 0;
}

vector<int> intersectList(int a[], int b[], int n)
{
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                output.push_back(a[i]);
            }
        }
    }
    return output;
}

vector<int> unionList(int a[], int b[], int n)
{
    vector<int> output;

    for (int i = 0; i < n; i++)
    {
        output.push_back(a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < output.size(); j++)
        {
            if (output[j] == b[i])
            {
                break;
            }
            if (j == output.size() - 1)
            {
                output.push_back(b[i]);
            }
        }
    }

    return output;
}