#!/usr/bin/python3
"""
Module checking how many operations are needed to get n operations
"""


def minOperations(n):
    """Function checking if it's possible to get n operations"""
    file = 'H'
    count = 0
    clipboard = ''

    # First copy all
    clipboard, count = copy_all(file, count)
    # First paste
    file, count = paste(file, clipboard, count)
    while True:
        length_file = len(file)
        if length_file == n:
            return count
        if length_file > n:
            return 0
        if n % length_file == 0:
            clipboard, count = copy_all(file, count)
            file, count = paste(file, clipboard, count)
        else:
            file, count = paste(file, clipboard, count)


def copy_all(file, count):
    """Function copying the file and increasing the count"""
    return file, count + 1


def paste(file, clipboard, count):
    """
    Function pasting the content of the clipboard to the file.
    Increase the count too.
    """
    return file + clipboard, count + 1
