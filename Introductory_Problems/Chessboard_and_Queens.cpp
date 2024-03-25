#include<iostream>
using namespace std;

int cnt;
bool isSafe(char grid[8][8], int row, int col)
{
	int tmpRow = row;
	int tmpCol = col;

	row = tmpRow;
	col = tmpCol;

	while (row >= 0 && col >= 0)
	{
		if (grid[row][col] == 'Q') return false;

		row--;
		col--;
	}

	row = tmpRow;
	col = tmpCol;

	while (col >= 0)
	{
		if (grid[row][col] == 'Q') return false;

		col--;
	}

	row = tmpRow;
	col = tmpCol;

	while (row >= 0 && col >= 0)
	{
		if (grid[row][col] == 'Q') return false;

		row++;
		col--;
	}

	return true;

}
void dfs(char grid[8][8], int col)
{
	if (col == 8)
	{
		cnt++;
		return;
	}

	for (int row = 0; row < 8; row++)
	{
		if (grid[row][col] != '*' && isSafe(grid, row, col))
		{
			grid[row][col] = 'Q';
			dfs(grid, col + 1);
			grid[row][col] = '.';
		}
	}
}

int main()
{
	char grid[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> grid[i][j];
		}
	}

	cnt = 0;
	dfs(grid, 0);
	cout << cnt;
}