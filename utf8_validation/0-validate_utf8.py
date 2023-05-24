#!/usr/bin/python3
"""Module checking if the given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """Checks if the data set given is a valid UTF-8 encoding"""
    n_bytes = 0
    for num in data:
        # If the number is less than 128, it's a single byte ASCII character
        if n_bytes == 0 and num < 128:
            continue
        binary = format(num, '08b')
        if n_bytes == 0:
            #Gets the number of bytes used for the current character
            n_bytes = binary.find('0')
            if n_bytes == 1 or n_bytes > 4:
                return False
        elif binary[:2] != '10':
            return False
        n_bytes -= 1
    return n_bytes == 0
