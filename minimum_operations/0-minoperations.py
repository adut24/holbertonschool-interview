#!/usr/bin/python3
"""Module to calculate the fewest number of operations needed to result"""


def minOperations(n):
    """
    Calculates the minimum number of operations needed to get n characters
    in a text file, starting with a single character.

    Args:
    - n (int): the number of characters to reach in the text file

    Returns:
    - int: The minimum number of operations needed to reach n characters
    """
    file_len = 1
    count = 0
    clipboard = 0

    # First copy all
    clipboard, count = copy_all(file_len, count)
    # First paste
    file_len, count = paste(file_len, clipboard, count)
    while True:
        if file_len == n:
            return count
        if file_len > n:
            return 0
        if n % file_len == 0:
            clipboard, count = copy_all(file_len, count)
        file_len, count = paste(file_len, clipboard, count)


def copy_all(file_len, count):
    """
    Copies all the contents of a file and increments the count by 1.

    Args:
    - file_len (int): the length of the file to be copied
    - count (int): the current count of operations

    Returns:
    - tuple: The length of the file and the incremented count of actions
    """
    return file_len, count + 1


def paste(file_len, clipboard, count):
    """
    Returns a tuple containing the new file length and the updated count after
    pasting the clipboard.

    Args:
    - file_len (int): the current length of the file
    - clipboard (int): the current length of the clipboard
    - count (int): the current count of operations performed

    Returns:
    - tuple: The new file length and the incremented count of actions
    """
    return file_len + clipboard, count + 1
