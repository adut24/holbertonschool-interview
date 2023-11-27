#!/usr/bin/python3
"""
Module for prime_game
"""


def isWinner(x, nums):
    """
    Returns name of player that won most rounds

    Args:
    - x: number of rounds
    - nums: array of integers

    Return:
    - str: name of player that won most rounds
    """
    if x <= 0:
        return None
    result = {'Maria': 0, 'Ben': 0}
    for n in nums:
        primes = generate_primes(n)
        turn = len(primes) % 2
        if turn == 1:
            result['Maria'] += 1
        else:
            result['Ben'] += 1
    if result['Maria'] > result['Ben']:
        return 'Maria'
    elif result['Ben'] > result['Maria']:
        return 'Ben'
    return None


def generate_primes(n):
    """
    Returns next prime number after n

    Args:
    - n: number

    Return:
    - int: next prime number after n
    """
    sieve = [True] * (n + 1)
    p = 2
    while p * p <= n:
        if sieve[p]:
            for i in range(p * p, n + 1, p):
                sieve[i] = False
        p += 1
    primes = [p for p in range(2, n + 1) if sieve[p]]
    return primes
