#!/usr/bin/python3
""" replaces a string in the heap memory of a running process
    Usage: ./read_write_heap.py <pid> <curr_pid> <new_pid>
    where <pid> is a pid, <curr_pid> is a string to search for in the heap, and
    <new_pid> replaces curr_pid.
"""
import sys
import re


def read_write_heap(pid, curr_pid, new_pid):
    """ replaces a string in the heap memory of a running process"""

    try:
        with open('/proc/{}/maps'.format(pid), 'r') as map:
            address_map = map.read()
            map.close()
    except FileNotFoundError as e:
        error_handler('{} Process Does Not Exist\n'.format(pid))

    regex = r'\b([\da-zA-Z]+)-([\da-zA-Z]+).*?\[heap]'
    heap_ranges = re.findall(regex, address_map)
    with open('/proc/{}/mem'.format(pid), 'r+b', 0) as mem:

        while True:
            try:
                start = int(heap_ranges[0][0], 16)
                end = int(heap_ranges[0][1], 16)
                mem.seek(start)
                buffer = mem.read(end - start)
                target_location = buffer.find(curr_pid)
                if target_location != -1:
                    mem.seek(start + target_location)
                    difference = max(len(curr_pid) - len(new_pid), 0)
                    mem.write(new_pid + bytes(difference))
                else:
                    heap_ranges.pop(0)
            except IndexError:
                break
        mem.close()


def error_handler(msg):
    """ prints error message and exits with error code 1 """
    print(msg)
    exit(1)


if __name__ == '__main__':

    if len(sys.argv) != 4:
        error_handler('Usage: {} pid curr_pid new_pid\n'.format
                      (sys.argv[0]))
    try:
        pid = int(sys.argv[1])
    except ValueError:
        error_handler('{}: first arg must be valid proccess id\n'.format
                      (sys.argv[0]))
    curr_pid = bytes(sys.argv[2], 'ascii')
    new_pid = bytes(sys.argv[3], 'ascii')

    read_write_heap(pid, curr_pid, new_pid)
