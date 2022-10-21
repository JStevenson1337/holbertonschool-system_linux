#!/usr/bin/python3

"""
This python script can modify the heap of a program by
searching for a target string. The replacement string
must be of shorter or equal to the length of the search
string.
Usage:
./read_write_heap.py <process ID> <search string> <replacement string>
"""

from multiprocessing import heap
from sys import argv

def get_heap_addrs(pid):
    """
    Find where the heap address are for a process ID.
    Usage: get_heap_addrs(<process id>)
    """
    if pid is not int:
        print(get_heap_addrs.__doc__)
        exit
    heap_start = ""
    heap_end = ""
    print("Searching for the heap addresses...")
    try:
        with open("/proc/{:d}/maps".format(pid), "r+b") as file:
            for line in file:
                if line.endswith("[heap]\n"):
                    heap_start = line.split(" ")[0].split("-", 2)[0]
                    heap_end = line.split(" ")[0].split("-", 2)[1]
                    print("Found: " + heap_start + " - " + heap_end)
    except Exception as error:
        print(error)
        exit
    return heap_start, heap_end


def replace_memory(pid, heap_start, heap_end, search_string, rep_string):
    """
    Replace the memory in the process ID by searching between
    the given addresses for the search string, and then replacing
    that search string with the replacement string
    Usage: get_heap_addrs(<process id>)
    """
    try:
        with open("/proc/{:d}/mem".format(pid), "r+b") as file:
            print("Searching for " + search_string)
            file.seek(heap_start)
            heap = file.read(heap_end - heap_start)
            position = heap.find(search_string.encode())
            if position > -1:
                location = heap_start + position
                print("Found string address at {:02X}").format(location)
                file.seek(location)
                written = file.write(rep_string.encode() + b'\x00')
            else:
                print("\n\nThe string was not found.")
                exit
    except Exception as excepts:
        print(excepts)
        exit

if __name__ == "__main__":
    """The entry point to the script. Usage ./read_write_heap.py <PID> <search string> <replacement string>"""
    if len(argv) < 4 or len(argv[3]) > len(argv[2]):
        print(__doc__)
        exit
    heap_start, heap_end = get_heap_addrs(int(argv[1]))
    replace_memory(int(argv[1]), heap_start, heap_end, argv[2], argv[3])
