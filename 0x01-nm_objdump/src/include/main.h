#ifndef __MAIN_H__
#define __MAIN_H__

#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define DEFAULT_STRING "hnm elf_filename\n"

/**
 * struct Elf - stores 32/64 structs and other data
 * @e64: the 64 bit struct
 * @e32: the 32 bit struct
 * @s64: the 64 bit struct section array
 * @s32: the 32 bit struct section array
 * @p64: the 64 bit struct program array
 * @p32: the 32 bit struct program array
 * @y64: the 64 bit struct symbol array
 * @y32: the 32 bit struct symbol array
 */
typedef struct Elf
{
	Elf64_Ehdr e64;
	Elf32_Ehdr e32;
	Elf64_Shdr *s64;
	Elf32_Shdr *s32;
	Elf64_Phdr *p64;
	Elf32_Phdr *p32;
	Elf64_Sym *y64;
	Elf32_Sym *y32;

} elf_t;


/* main.c prototypes */
int read_in_file(char *file_name, int multiple, char **argv);


#endif /* __MAIN_H__ */
