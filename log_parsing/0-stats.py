#!/usr/bin/python3
"""Module reading stdin and computing metrics"""
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
    """Handle when CTRL + C is pressed"""
    print_infos()


def print_infos():
    """Prints the stats obtained from the file"""
    print("File size: {}".format(file_size))
    for key, value in sorted(stats.items()):
        if value != 0:
            print("{:s}: {:d}".format(key, value))


signal.signal(signal.SIGINT, signal_handler)
for line in sys.stdin:
    count += 1
    line_parsed = line.split()
    if len(line_parsed) != 9:
        continue
    file_size += int(line_parsed[8])
    if line_parsed[7] not in stats.keys():
        continue
    stats[line_parsed[7]] += 1
    if count % 10 == 0:
        print_infos()
print_infos()
