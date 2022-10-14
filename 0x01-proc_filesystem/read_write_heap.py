#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Python script to change the memory value in the heap of a process
Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>
"""

from re import findall
from sys import argv


def read_write_heap(pid, target, replacement):
    """ finds and replaces target string in heap of a running process"""

    try:
        with open('/proc/{}/maps'.format(pid), 'r') as mmap_file:
            mmap_char_map = mmap_file.read()
            mmap_file.close()
    except FileNotFoundError as e:
        error_out('{} does not represent a running process.\n'.format(pid))

    pattern = r'\b([\da-zA-Z]+)-([\da-zA-Z]+).*?\[heap]'
    # re.findall() returns a list of tuples of the captured groups
    heap_ranges_from_mmap = findall(pattern, mmap_char_map)
    with open('/proc/{}/mem'.format(pid), 'r+b', 0) as mem_file:
        print('heap ranges: {}'.format(heap_ranges_from_mmap))

        for heap_range in heap_ranges_from_mmap:
            start = int(heap_range[0], 16)
            end = int(heap_range[1], 16)
            mem_file.seek(start)
            buffer = mem_file.read(end - start)
            target_location = buffer.find(target)

            if target_location != -1:
                mem_file.seek(start + target_location)
                print('Found {} at {}'.format(target, hex(start + target_location)))
                difference = max(len(target) - len(replacement), 0)
                print('Difference: {} in bytes'.format(difference))
                mem_file.write(replacement + bytes(difference))
                print('Replaced with {}'.format(replacement))
                break
        mem_file.close()


def error_out(error_msg):
    """ prints error message and exits with error code 1 """
    print(error_msg)
    exit(1)


if __name__ == '__main__':

    if len(argv) != 4:
        error_out('Usage: {} pid target_str replacement_str\n'.format(argv[0]))

    try:
        pid = int(argv[1])
    except ValueError:
        error_out('{}: first arg must be valid proccess id\n'.format(argv[0]))

    target = bytes(argv[2], 'ascii')
    replacement = bytes(argv[3], 'ascii')

    # Let's do this!
    read_write_heap(pid, target, replacement)
    print('Successfully Updated Memory')
    exit(0)
