#!/usr/bin/python3
"""
Module checking how many operations are needed to get n operations
"""


def minOperations(n):
    """Function checking if it's possible to get n operations"""
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
    """Function copying the file and increasing the count"""
    return file_len, count + 1


def paste(file_len, clipboard, count):
    """
    Function pasting the content of the clipboard to the file.
    Increase the count too.
    """
    return file_len + clipboard, count + 1
