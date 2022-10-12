#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Python script to change the memory value in the heap of a process
Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>
"""
import sys
import os
import re


def read_write_heap(pid, search_string, replace_string):
    """ Read and write the heap of a process """
    # check if the process exists
    if not os.path.exists("/proc/{}/mem".format(pid)):
        error_handler("Process {} does not exist".format(pid))

    # check if the search string exists
    try:
        with open("/proc/{}/maps".format(pid), "r") as f:
            maps = f.read()
    except IOError as e:
        error_handler("Error reading /proc/{}/maps: {}".format(pid, e))

    # check if the search string exists
    if search_string not in maps:
        error_handler("Search string {} not found".format(search_string))

    # read the memory of the process
    try:
        with open("/proc/{}/mem".format(pid), "rb+") as f:
            mem = f.read()
    except IOError as e:
        error_handler("Error reading /proc/{}/mem: {}".format(pid, e))

    # search and replace the string
    mem = mem.replace(search_string.encode(), replace_string.encode())

    # write the memory of the process
    try:
        with open("/proc/{}/mem".format(pid), "wb") as f:
            f.write(mem)
    except IOError as e:
        error_handler("Error writing /proc/{}/mem: {}".format(pid, e))


def error_handler(msg):
    """ Print error message and exit """
    print(msg)
    sys.exit(1)


def main():
    """ Main function """
    # check if the arguments are correct
    if len(sys.argv) != 4:
        error_handler(
            "Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>")

    # get the arguments
    pid = sys.argv[1]
    search_string = sys.argv[2]
    replace_string = sys.argv[3]

    # call the function
    read_write_heap(pid, search_string, replace_string)


if __name__ == "__main__":
    main()
