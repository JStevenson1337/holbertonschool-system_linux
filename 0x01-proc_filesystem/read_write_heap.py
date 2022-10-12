#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Python script to change the memory value in the heap of a process
Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>
"""
import sys
import re


def read_write_heap(pid, search_string, replace_string):
    """ Read and write the heap of a process """
    # check if the pid is a number
    if not pid.isdigit():
        error_handler("The pid must be a number")

    # check if the pid exists
    try:
        with open("/proc/{}/maps".format(pid), "r") as maps:
            pass
    except FileNotFoundError:
        error_handler("The pid does not exist")

    # open the maps file
    with open("/proc/{}/maps".format(pid), "r") as maps_file:
        # read the maps file
        maps = maps_file.read()

    # get the heap address
    heap_address = re.search(r"\[heap\](.*)", maps).group(1).split("-")[0]

    # open the memory file
    with open("/proc/{}/mem".format(pid), "r+b") as mem_file:
        # read the memory file
        mem = mem_file.read()

        # get the index of the search string
        index = mem.find(bytes(search_string, "ASCII"))

        # check if the search string was found
        if index == -1:
            error_handler("The search string was not found")

        # change the memory value
        mem_file.seek(int(heap_address, 16) + index)
        mem_file.write(bytes(replace_string, "ASCII"))


def error_handler(error):
    """ Print the error and exit """
    print(error)
    sys.exit(1)


if __name__ == "__main__":
    # check the arguments
    if len(sys.argv) != 4:
        error_handler(
            "Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>")

    # read and write the heap
    read_write_heap(sys.argv[1], sys.argv[2], sys.argv[3])
