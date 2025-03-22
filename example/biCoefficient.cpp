#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> mem;

void resetMem(int n)
{
	mem.assign(n + 1, vector<int>(n + 1, -1));
}

int c_t(int n, int k)
{
	if (k == 0 || n == 0 || n == k)
	{
		return 1;
	}
	if (mem[n][k] != -1)
	{
		return mem[n][k];
	}
	mem[n][k] = c_t(n - 1, k - 1) + c_t(n - 1, k);
	return mem[n][k];
}

int c_d(int n, int k)
{
	mem[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j == 0)
			{
				mem[i][j] = 1;
				continue;
			}
			if (j == i)
			{
				mem[i][j] = 1;
				break;
			}
			mem[i][j] = mem[i - 1][j - 1] + mem[i - 1][j];
		}
	}
	return mem[n][k];
}

int main()
{

	int n = 6;
	int k = 2;
	resetMem(n);
	cout << c_t(n, k) << endl;

	resetMem(n);
	cout << c_d(n, k) << endl;
	for (auto i : mem)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
	return 0;
}
