#!/usr/bin/python3
"""Module to make change using the fewest number of coins"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given total.

    Args:
    - coins (list): integers representing the coin denominations
    - total (int): the total amount of money

    Returns:
    - int: the minimum number of coins needed to make the change
    """
    if total <= 0:
        return 0
    coins_needed = [float('inf')] * (total + 1)
    coins_needed[0] = 0
    for i in range(1, total + 1):
        for coin in coins:
            if i - coin >= 0:
                coins_needed[i] = min(coins_needed[i],
                                      coins_needed[i - coin] + 1)
    return -1 if coins_needed[total] == float('inf') else coins_needed[total]
