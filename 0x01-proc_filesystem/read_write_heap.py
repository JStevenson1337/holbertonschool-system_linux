#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys
import psutil
import os

"""
Python script to change the memory value in the heap
"""
def read_write_heap(pid, search_string, replace_string):
    for proc in psutil.process_iter():
        try:
            # Get process name & pid from process object
            processName = proc.name()
            processID = proc.pid
            print(processName ,  ' ::: ', processID)
        except (psutil.NoSuchProcess, psutil.AccessDenied, psutil.ZombieProcess):
            pass





if __name__=="__main__":
    print(f"Arguments count: {len(sys.argv)}")
    for i, arg in enumerate(sys.argv):
        print(f"Argument {i:>6}: {arg}")

