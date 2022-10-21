#!/usr/bin/python3
import subprocess
import time

search_string = "Holb"
replace_string = "NNOE"

proc_c = subprocess.Popen(['./main_c'])
pid = proc_c.pid
time.sleep(1)

add_in_memory = None

maps_filename = "/proc/{}/maps".format(pid)
mem_filename = "/proc/{}/mem".format(pid)

def read_value_in_memory(path, addr, l):
    value_read = None
    # write the new string
    if add_in_memory is not None:
        try:
            mem_file = open(path, 'rb')
            mem_file.seek(addr)
            value_read = mem_file.read(l)
        except Exception as e:
            print(e)
        finally:
            mem_file.close()
    return value_read

try:
    with open(maps_filename, mode="r") as maps_file:
        while True:
            line = maps_file.readline()
            if not line:
                break
            sline = line.split(' ')
            
            try:
                # check iif we found the heap
                if (sline[-1][:-1] == "[heap]"):
                    
                    # parse line
                    addr = sline[0]
                    perm = sline[1]
                    offset = sline[2]
                    device = sline[3]
                    inode = sline[4]
                    pathname = sline[-1][:-1]
                    
                    # get start and end of mem
                    addr = addr.split("-")
                    addr_start = int(addr[0], 16)
                    addr_end = int(addr[1], 16)
                    
                    # open and read mem
                    try:
                        mem_file = open(mem_filename, 'rb')
                        # read heap
                        mem_file.seek(addr_start)
                        heap = mem_file.read(addr_end - addr_start)
                        # find string
                        try:
                            add_in_memory = heap.index(bytes(search_string, "ASCII"))
                            add_in_memory += addr_start
                        except Exception as e:
                            print(e)
                        mem_file.close()
                    except Exception as e:
                        print(e)
                    
                    break
            except Exception as e:
                print(e)

    previous_value = read_value_in_memory(mem_filename, add_in_memory, len(search_string))

    # start py prog
    proc_py = subprocess.Popen(['./read_write_heap.py', str(pid), search_string, replace_string])
    time.sleep(2)
    new_value = read_value_in_memory(mem_filename, add_in_memory, len(search_string))

    if previous_value != new_value:
        print("SUCCESS!")
    else:
        print("FAIL!")
except Exception as e:
    print(e)
finally:
    proc_c.kill()
    proc_py.kill()
