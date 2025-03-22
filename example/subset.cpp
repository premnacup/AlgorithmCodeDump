#include <bits/stdc++.h>
using namespace std;

void print_sol(int x[], int arr[], int n)
{
	int sum = 0;

	// Subset1
	// for (int i = 1; i <= n; i++)
	// {
	// 	if (x[i] == 1)
	// 	{
	// 		sum += arr[i - 1];
	// 	}
	// }

	// cout << "Sequence: ";
	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << x[i];
	// }
	// cout << endl;

	// cout << "Value: ";
	// for (int i = 1; i <= n; i++)
	// {
	// 	if (x[i] == 1)
	// 	{
	// 		cout << arr[i - 1] << " ";
	// 	}
	// }
	// cout << endl;
	// cout << "Sum : " << sum << endl;

	// Subset2
	for (int i = 1; i <= n; i++)
	{
		sum += arr[x[i] - 1];
	}

	cout << "Sequence: ";
	for (int i = 1; i <= n; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;

	cout << "Value: ";
	for (int i = 1; i <= n; i++)
	{
		cout << arr[x[i] - 1] << " ";
	}
	cout << endl;
	cout << "Sum : " << sum << endl;

	cout << endl;
}

void subset1(int x[], int arr[], int l, int r)
{
	if (l == r)
	{
		print_sol(x, arr, r);
	}
	else
	{
		x[l + 1] = 0;
		subset1(x, arr, l + 1, r);
		x[l + 1] = 1;
		subset1(x, arr, l + 1, r);
	}
}

void subset2(int x[], int arr[], int l, int n)
{
	print_sol(x, arr, l);
	int j;
	if (l == 0)
	{
		j = 1;
	}
	else
	{
		j = x[l] + 1;
	}

	for (int i = j; i <= n; i++)
	{
		x[l + 1] = i;
		subset2(x, arr, l + 1, n);
	}
}

int main()
{
	int arr[] = {25, 10, 9, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x[n + 1];

	//	subset1(x, arr, 0, n);
	subset2(x, arr, 0, n);
	return 0;
}
