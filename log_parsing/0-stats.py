#!/usr/bin/python3
"""Module to parse a log file"""
import signal
import sys


stats = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}
count = 0
file_size = 0


def signal_handler(sig, frame):
    """
    Prints the stats obtained from the file when a keyboard interrupt occurs.

    Args:
    - sig: The signal number
    - frame: The current stack frame
    """
    print_infos()


def print_infos():
    """
    Prints the file size and statistics for a given log file.
    """
    print("File size: {}".format(file_size))
    for key, value in sorted(stats.items()):
        if value != 0:
            print("{:s}: {:d}".format(key, value))


signal.signal(signal.SIGINT, signal_handler)
for line in sys.stdin:
    count += 1
    line_parsed = line.split()
    length_line = len(line_parsed)
    if length_line < 2:
        continue
    file_size += int(line_parsed[length_line - 1])
    if line_parsed[length_line - 2] not in stats.keys():
        continue
    stats[line_parsed[length_line - 2]] += 1
    if count % 10 == 0:
        print_infos()
print_infos()
