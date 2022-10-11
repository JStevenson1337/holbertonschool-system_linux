#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Python script to change the memory value in the heap of a process
Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>
"""
import sys
import re
import os


def read_write_heap(pid, search_string, replace_string):
    for proc in os.listdir('/proc'):
        try:
            with open('/proc/{}/maps'.format(pid), 'r') as f:
                pid_f = f.read()
                f.close()
        except:
            error_handler(
                f'Error: Could not open /proc/{pid}/maps'.format(pid))
            sys.exit(1)

        regex = r'\b([\da-zA-Z]+)-([\da-zA-Z]+) r--p ([\da-zA-Z]+) ([\da-zA-Z]+:[\da-zA-Z]+) \d+ \S+'
        for match in re.finditer(regex, pid_f):
            if match:
                start = int(match.group(1), 16)
                end = int(match.group(2), 16)
                offset = int(match.group(3), 16)
                inode = match.group(4)
                if inode != '00:00':
                    try:
                        with open('/proc/{}/mem'.format(pid), 'rb+') as f:
                            f.seek(start)
                            mem = f.read(end - start)
                            f.close()
                    except:
                        error_handler(
                            f'Error: Could not open /proc/{pid}/mem'.format(pid))
                        sys.exit(1)
                    if search_string in mem:
                        print(
                            f'Found "{search_string}" in memory at {hex(start)}')
                        print(
                            f'Writing "{replace_string}" to memory at {hex(start)}')
                        try:
                            with open('/proc/{}/mem'.format(pid), 'rb+') as f:
                                f.seek(start)
                                f.write(replace_string.encode())
                                f.close()
                        except:
                            error_handler(
                                f'Error: Could not open /proc/{pid}/mem'.format(pid))
                            sys.exit(1)


def error_handler(msg):
    """ Print error message and exit """
    print(msg)
    sys.exit(1)


if __name__ == "__main__":
    if len(sys.argv) != 4:
        error_handler(
            'Usage: {} <pid> <search_string> <replace_string>'.format(sys.argv[0]))
        sys.exit(1)
    else:
        read_write_heap(sys.argv[1], sys.argv[2], sys.argv[3])
