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
    result = {'Maria': 0, 'Ben': 0}
    for i in range(x):
        numbers = [n for n in range(1, nums[i] + 1)]
        if numbers == [1]:
            result['Ben'] += 1
            continue
        j = 0
        choice = 2
        while numbers != [1]:
            turn = 'Maria' if j % 2 == 0 else 'Ben'
            numbers = [n for n in numbers if n % choice != 0]
            choice = get_next_prime(choice)
            j += 1
        result[turn] += 1
    if result['Maria'] > result['Ben']:
        return 'Maria'
    elif result['Ben'] > result['Maria']:
        return 'Ben'
    return None


def is_prime(x):
    """
    Checks if number is prime

    Args:
    - x: number

    Return:
    - bool: True if number is prime, False otherwise
    """
    return all(x % i for i in range(2, x))


def get_next_prime(x):
    """
    Returns next prime number after x

    Args:
    - x: number

    Return:
    - int: next prime number after x
    """
    return min([a for a in range(x + 1, 2 * x) if is_prime(a)])
