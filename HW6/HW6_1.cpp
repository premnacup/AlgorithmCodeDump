#include <bits/stdc++.h>
using namespace std;

/**
 * Prints the array x from index 0 to n-1.
 */
void printAns(char x[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

/**
 * Rotates the array x from index i to j to the right by one position.
 */
void rightRotate(char x[], int i, int j)
{
    int temp = x[j];            // Store the last element of the rotation
    for (int k = j; k > i; k--) // Move all elements from j to i one position to the right
    {
        x[k] = x[k - 1];
    }
    x[i] = temp; // Put the stored element in the position of the first element of the rotation
}

/**
 * Rotates the array x from index i to j to the left by one position.
 */
void leftRotate(char x[], int i, int j)
{
    int temp = x[i];            // Store the first element of the rotation
    for (int k = i; k < j; k++) // Move all elements from i to j one position to the left
    {
        x[k] = x[k + 1];
    }
    x[j] = temp; // Put the stored element in the position of the last element of the rotation
}

/**
 * Generates all permutations of the array x from index start to end.
 */
void permute(char x[], int start, int end)
{
    if (start == end) // If we have reached the end of the array, print the permutation
    {
        printAns(x, end);
        return;
    }

    permute(x, start + 1, end); // Recursively generate permutations for the rest of the array

    for (int j = start + 1; j < end; j++) // For each element in the array from start+1 to end-1
    {
        rightRotate(x, start, j);   // Rotate the array to the right by one position
        permute(x, start + 1, end); // Recursively generate permutations for the rest of the array
        leftRotate(x, start, j);    // Rotate the array to the left by one position
    }
}

int main()
{
    int n;
    cin >> n;
    char x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    permute(x, 0, n);

    return 0;
}
