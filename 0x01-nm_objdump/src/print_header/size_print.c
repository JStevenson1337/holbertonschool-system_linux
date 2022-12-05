#include "../common_tools/common_tools.h"
#include "print_header.h"
/**
 * print_hsize - prints the hsize number of an ELF file
 * @hsize: array of bytes in the ELF file
 * @hsize_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_hsize(Elf32_Half hsize, Elf32_Half hsize_32, int selector)
{
	char *info = "  Size of this header:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("%d (bytes)\n", hsize);
	else
		printf("%d (bytes)\n", hsize_32);
}

/**
 * print_phsize - prints the phsize number of an ELF file
 * @phsize: array of bytes in the ELF file
 * @phsize_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_phsize(Elf32_Half phsize, Elf32_Half phsize_32, int selector)
{
	char *info = "  Size of program headers:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("%d (bytes)\n", phsize);
	else
		printf("%d (bytes)\n", phsize_32);
}

/**
 * print_nsize - prints the nsize number of an ELF file
 * @nsize: array of bytes in the ELF file
 * @nsize_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_nsize(Elf32_Half nsize, Elf32_Half nsize_32, int selector)
{
	char *info = "  Number of program headers:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("%d\n", nsize);
	else
		printf("%d\n", nsize_32);
}

/**
 * print_shsize - prints the shsize number of an ELF file
 * @shsize: array of bytes in the ELF file
 * @shsize_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
int print_shsize(Elf32_Half shsize, Elf32_Half shsize_32, int selector)
{
	if (selector == 2)
		return ((int) shsize);
	else
		return ((int) shsize_32);
}

/**
 * print_shnum - prints the shnum number of an ELF file
 * @shnum: array of bytes in the ELF file
 * @shnum_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
int print_shnum(Elf32_Half shnum, Elf32_Half shnum_32, int selector)
{
	if (selector == 2)
		return ((int) shnum);
	else
		return ((int) shnum_32);
}

