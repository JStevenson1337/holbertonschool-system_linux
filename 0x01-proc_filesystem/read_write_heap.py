#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Python script to change the memory value in the heap of a process
Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>
"""
from sys import argv
from os import sys
import re
from xml.sax import ErrorHandler


def read_write_heap(pid, search_string, replace_string):
    """ Read and write the heap of a process """
    # check if the pid is a number
    if not pid.isdigit():
        ErrorHandler("The pid must be a number")

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
    print("Heap address: {}".format(heap_address))

    # open the memory file
    with open("/proc/{}/mem".format(pid), "rb+") as mem_file:
        # read the memory file
        mem = mem_file.read()

        # search the string in the memory
        search_string_address = mem.find(bytes(search_string, "utf-8"))
        print("Search string address: {}".format(hex(search_string_address)))

        # replace the string in the memory
        mem_file.seek(search_string_address)
        mem_file.write(bytes(replace_string, "utf-8"))


def error_handler(error):
    """ Print the error and exit """
    print(error)
    sys.exit(1)


if __name__ == "__main__":
    # check the arguments
    if len(argv) != 4:
        error_handler(
            "Usage: python3 read_write_heap.py <pid> <search_string> <replace_string>")

    # get the arguments
    pid = argv[1]
    search_string = argv[2]
    replace_string = argv[3]

    # read and write the heap
    read_write_heap(pid, search_string, replace_string)
