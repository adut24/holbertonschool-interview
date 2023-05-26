#!/usr/bin/python3
"""Module checking if the given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """Checks if the data set given is a valid UTF-8 encoding"""
    n_bytes = 0
    for num in data:
        if n_bytes == 0:
            mask = 128
            # Counting the ones at the start to know the number of bytes
            while mask & num:
                n_bytes += 1
                mask = mask * 2
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        # If the first bit is not 1 and the second not 0
        elif not (num & 128 and not (num & 64)):
            return False
        n_bytes -= 1
    return n_bytes == 0
