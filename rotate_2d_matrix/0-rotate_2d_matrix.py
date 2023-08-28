#!/usr/bin/python3
"""Module to rotate a 2D matrix"""


def rotate_2d_matrix(matrix):
    """Rotates a 2D matrix"""
    length = len(matrix[0])
    for i in range(length // 2):
        for j in range(i, length - i - 1):
            tmp = matrix[i][j]
            matrix[i][j] = matrix[length - j - 1][i]
            matrix[length - j - 1][i] = matrix[length - i - 1][length - j - 1]
            matrix[length - i - 1][length - j - 1] = matrix[j][length - i - 1]
            matrix[j][length - i - 1] = tmp
            