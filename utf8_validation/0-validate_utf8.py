#!/usr/bin/python3
"""Module checking if the given data set represents a valid UTF-8 encoding"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Args:
    - data (list): integers representing the bytes of the data set

    Returns:
    - bool: True if the data set represents a valid UTF-8 encoding, else False
    """
    num_bytes = 0
    for byte in data:
        # Check if the byte is a continuation byte
        if num_bytes == 0:
            # 2-bytes character
            if byte >> 5 == 0b110:
                num_bytes = 1
            # 3-bytes character
            elif byte >> 4 == 0b1110:
                num_bytes = 2
            # 4-bytes character
            elif byte >> 3 == 0b11110:
                num_bytes = 3
            # ASCII character
            elif byte >> 7 == 0b0:
                continue
            # Invalid character
            else:
                return False
        else:
            # Check if the byte is a valid continuation byte
            if byte >> 6 != 0b10:
                return False
            num_bytes -= 1
    # Check if there are any incomplete characters
    return num_bytes == 0
