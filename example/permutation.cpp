#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int countP = 0;
void permute(int x[], int start, int end)
{
	if (start == end)
	{
		for (int i = 1; i <= end; i++)
		{
			cout << x[i];
		}
		countP++;
		cout << endl;
		return;
	}

	for (int i = start; i <= end; i++)
	{
		swap(&x[start], &x[i]);
		permute(x, start + 1, end);
		swap(&x[start], &x[i]);
	}
}

int main()
{
	int n;
	cin >> n;
	int x[n];
	x[0] = -1;
	for (int i = 1; i <= n; i++)
	{
		x[i] = i;
	}
	permute(x, 1, n);
	cout << countP << endl;

	return 0;
}
