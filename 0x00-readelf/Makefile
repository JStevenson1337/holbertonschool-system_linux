CC        = gcc
CFLAGS    = -g3 -Wall -Werror -Wextra -pedantic
MAIN_FILE = hreadelf.c
MAIN_HEADER = hreadelf.h

build:
	@echo "compiling"
0-hreadelf: $(MAIN_FILE) $(MAIN_HEADER)
	$(CC) $(CFLAGS) -o $@ $^

1-hreadelf: $(MAIN_FILE) $(MAIN_HEADER) get_ELF_file_type.c get_string_table.c
	$(CC) $(CFLAGS) -DPRINT_ELF_HEADER -o $@ $^

2-hreadelf: $(MAIN_FILE) $(MAIN_HEADER) get_ELF_file_type.c get_string_table.c
	$(CC) $(CFLAGS) -DPRINT_ELF_HEADER -DPRINT_ELF_SECTION_HEADER -o $@ $^

clean:
	rm -f 0-hreadelf 1-hreadelf 2-hreadelf


