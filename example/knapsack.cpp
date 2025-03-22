#include <bits/stdc++.h>
using namespace std;
int maxValue = -1;
int k = 18;
int ans[4];

/**
 * @brief Print the solution of the knapsack problem
 * @param x The binary vector of the solution
 * @param arr The array of the weights of the items
 * @param arr2 The array of the values of the items
 * @param n The size of the arrays
 */
void print_sol(int x[], int arr[], int arr2[], int n)
{
	int sumWeight = 0; // The sum of the weights of the items in the solution
	int sumValue = 0; // The sum of the values of the items in the solution

	// Calculate the sum of the weights and values of the items in the solution
	for (int i = 1; i <= n; i++)
	{
		if (x[i] == 1)
		{
			sumWeight += arr[i - 1];
			sumValue += arr2[i - 1];
		}
	}

	// If the sum of the weights is less or equal to 18 and the sum of the values is greater than the maxValue
	if (sumWeight <= 18 && sumValue > maxValue)
	{
		maxValue = sumValue; // Update the maxValue

		// Print the solution
		cout << "Sequence: ";
		for (int i = 1; i <= n; i++)
		{
			cout << x[i];
			ans[i - 1] = x[i];
		}
		cout << endl;

		cout << "Weight: ";
		for (int i = 1; i <= n; i++)
		{
			if (x[i] == 1)
			{
				cout << arr[i - 1] << " ";
			}
		}
		cout << endl;

		cout << "Value: ";
		for (int i = 1; i <= n; i++)
		{
			if (x[i] == 1)
			{
				cout << arr2[i - 1] << " ";
			}
		}
		cout << endl;

		cout << "sumWeight : " << sumWeight << endl;
		cout << "sumValue : " << sumValue << endl;
		cout << endl;
	}
}

/**
 * @brief Print all the subsets of the array using a recursive approach
 * @param x The binary vector of the subset
 * @param arr The array of the weights of the items
 * @param arr2 The array of the values of the items
 * @param l The starting index of the subset
 * @param r The ending index of the subset
 */
void subset1(int x[], int arr[], int arr2[], int l, int r)
{
	// If the starting index is equal to the ending index, print the subset
	if (l == r)
	{
		print_sol(x, arr, arr2, r);
	}
	else
	{
		// Set the element at the current index to 0
		x[l + 1] = 0;
		
		// Recursively call the function with the next index
		subset1(x, arr, arr2, l + 1, r);
		
		// Set the element at the current index to 1
		x[l + 1] = 1;
		
		// Recursively call the function with the next index
		subset1(x, arr, arr2, l + 1, r);
	}
}

int main()
{
	int weight[] = {12, 5, 4, 2};
	int value[] = {8, 7, 4, 2};

	int n = sizeof(weight) / sizeof(weight[0]);
	int x[n + 1];

	subset1(x, weight, value, 0, n);

	cout << "Weight: ";
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 1)
		{
			cout << weight[i] << " ";
		}
	}
	cout << endl;
	cout << "Value: ";
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 1)
		{
			cout << value[i] << " ";
		}
	}
	return 0;
}
