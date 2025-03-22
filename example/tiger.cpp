#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> mem;

void resetMem(int n1, int n2)
{
	mem.assign(n1, vector<int>(n2, -1));
}

int solve(int x, int y)
{
	if (x == 0 || y == 0)
	{
		mem[x][y] = 1;
		return 1;
	}
	if (mem[x][y] != -1)
	{
		return mem[x][y];
	}
	mem[x][y] = solve(x, y - 1) + solve(x - 1, y);
	return mem[x][y];
}

int main()
{
	int m, n;
	cin >> m >> n;
	resetMem(m, n);

	cout << solve(m - 1, n - 1) << endl;
	return 0;
}
