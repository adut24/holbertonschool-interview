#!/usr/bin/python3
"""Module to solve the N-Queens problem"""
import sys


def add_solution(board, result, n):
    """
    Adds a solution to the result list.

    Args:
    - board (list): the current state of the board
    - result (list): all valid solutions
    - n (int): the size of the board
    """
    temp = []
    for i in range(n):
        for j in range(n):
            if board[i][j] == 1:
                temp.append([i, j])
    result.append(temp)


def is_safe(row, col, board, n):
    """
    Determines if it is safe to place a queen at a given position on the board.

    Args:
    - row (int): the row to check
    - col (int): the column to check
    - board (list): the current state of the board
    - n (int): the size of the board

    Returns:
    - bool: True if it is safe to place a queen at the position, else False
    """
    x = row
    while x >= 0:
        if board[x][col] == 1:
            return False
        x -= 1
    x = row
    y = col
    while x >= 0 and y < n:
        if board[x][y] == 1:
            return False
        y += 1
        x -= 1
    x = row
    y = col
    while x >= 0 and y >= 0:
        if board[x][y] == 1:
            return False
        y -= 1
        x -= 1
    return True


def solve_nqueens(row, result, board, n):
    """
    Recursively solve the N-Queens problem for a given row and board size.

    Args:
    - row (int): the current row being processed
    - result (list): the solutions found
    - board (list): the current state of the board
    - n (int): the size of the board
    """
    if row == n:
        add_solution(board, result, n)
        return
    for col in range(n):
        if is_safe(row, col, board, n):
            board[row][col] = 1
            solve_nqueens(row + 1, result, board, n)
            board[row][col] = 0


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)
    if n < 4:
        print('N must be at least 4')
        sys.exit(1)

    result = []
    board = [[0 for _ in range(n)] for _ in range(n)]
    solve_nqueens(0, result, board, n)
    for solution in result:
        print(solution)
