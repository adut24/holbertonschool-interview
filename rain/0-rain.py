#!/usr/bin/python3
"""
Module calculating square units of water
"""


def rain(walls):
    """
    Calculates how many square units of water will be retained after it rains.
    """
    result = 0
    walls_length = len(walls)

    for i in range(1, walls_length - 1):

        left_wall = walls[i]
        for j in range(i):
            left_wall = max(left_wall, walls[j])

        right_wall = walls[i]
        for j in range(i + 1, walls_length):
            right_wall = max(right_wall, walls[j])

        result += min(left_wall, right_wall) - walls[i]

    return result
