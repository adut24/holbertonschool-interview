#!/usr/bin/python3
"""Module that calculates the perimeter of an island in a grid"""


def island_perimeter(grid):
    """
    Calculates the perimeter of an island in a grid.

    Args:
    - grid (list): integers representing the map

    Returns:
    - int: the perimeter of the island
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                perimeter += find_water(grid, i, j)
    return perimeter


def find_water(grid, row, col):
    """
    Find the number of water cells adjacent to the given cell in a grid.

    Args:
    - grid (list): integers representing the map
    - row (int): the row number of the cell
    - col (int): the column number of the cell

    Returns:
    - int: the count of water cells adjacent to the given cell
    """
    len_row = len(grid) - 1
    len_col = len(grid[row]) - 1
    count = 0
    # Check left
    if (col > 0 and not grid[row][col - 1]) or col == 0:
        count += 1
    # Check right
    if (col < len_col and not grid[row][col + 1]) or col == len_col:
        count += 1
    # Check up
    if (row > 0 and not grid[row - 1][col]) or row == 0:
        count += 1
    # Check down
    if (row < len_row and not grid[row + 1][col]) or row == len_row:
        count += 1
    return count
