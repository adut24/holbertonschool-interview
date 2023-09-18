#!/usr/bin/python3
"""0-making_change module"""


def makeChange(coins, total):
    """Count the number of coin needed to hand the change"""
    if total <= 0:
        return 0
    nbCoin = 0
    for coin in sorted(coins, reverse=True):
        if total == 0:
            break
        while total >= coin:
            nbCoin += 1
            total -= coin
    return nbCoin if total == 0 else -1
