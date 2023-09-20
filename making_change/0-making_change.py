#!/usr/bin/python3
"""0-making_change module"""


def makeChange(coins, total):
    """Count the number of coin needed to hand the change"""
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
