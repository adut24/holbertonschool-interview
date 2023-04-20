#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int copy_grid[3][3];
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!is_stable_sandpile(grid1))
	{
		copy_sandpile(grid1, copy_grid);

		if (!is_stable_sandpile(grid1))
		{
			printf("=\n");
			print_grid(grid1);
		}
		
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (copy_grid[i][j] > 3)
					sandpile_toppling(grid1, copy_grid, i, j);
			}
		}
	}
}

/**
 * is_stable_sandpile - checks if the sandpile is stable or not
 * @grid: sandpile to check
 * Return: 1 if it's stable or 0 if not
 */
int is_stable_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * copy_sandpile - copy the content of a sandpile
 * @src: sandpile to copy
 * @dst: sandpile to receive the copy
 */
void copy_sandpile(int src[3][3], int dst[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			dst[i][j] = src[i][j];
	}
}

/**
 * sandpile_toppling - topple a cell from the sandpile
 * @grid1: sandpile to topple
 * @grid2: copy of the sandpile
 * @row: index of the row of the cell to topple
 * @column: index of the column of the cell to topple
 */
void sandpile_toppling(int grid1[3][3], int grid2[3][3], int row, int column)
{
	int row_offsets[] = {-1, 0, 1, 0};
	int col_offsets[] = {0, -1, 0, 1};
	int i;

	for (i = 0; i < 4; i++)
	{
		int new_row = row + row_offsets[i];
		int new_col = column + col_offsets[i];

		if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3)
		{
			if (grid2[new_row][new_col] <= 3)
			{
				grid1[new_row][new_col]++;
				grid1[row][column]--;
			}
		}
		else
			grid1[row][column]--;
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
