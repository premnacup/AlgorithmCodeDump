#include <iostream>
#include <cmath>
using namespace std;
int countDigits(int);
int multiply(int, int);

int main()
{
    int a, b;
    cin >> a >> b;
    cout << multiply(a, b);
    return 0;
}

int countDigits(int n)
{
    int digitlength = 0;
    while (n != 0)
    {
        n = n / 10;
        digitlength++;
    }
    return digitlength;
}

int multiply(int a, int b)
{
    int lengthA = countDigits(a);
    int lengthB = countDigits(b);
    int result = 0;
    if (lengthA <= 1)
    {
        return a * b;
    }

    int n = max(lengthA, lengthB);
    int half = n / 2;

    int a1 = a / pow(10, half);
    int a2 = a % (int)pow(10, half);
    int b1 = b / pow(10, half);
    int b2 = b % (int)pow(10, half);

    int A = multiply(a1, b1);
    int B = multiply(a2, b2);
    int C = multiply(a1 + a2, b1 + b2);

    cout << A << " " << B << " " << C << endl;

    return A * pow(10, 2 * half) + (C - A - B) * pow(10, half) + B;
}
