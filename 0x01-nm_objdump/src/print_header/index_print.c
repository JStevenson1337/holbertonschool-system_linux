#include "../common_tools/common_tools.h"
#include "print_header.h"
/**
 * print_tindex - prints the tindex number of an ELF file
 * @tindex: array of bytes in the ELF file
 * @tindex_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_tindex(Elf32_Half tindex, Elf32_Half tindex_32, int selector)
{
	char *info = "  Section header string table index:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("%d\n", tindex);
	else
		printf("%d\n", tindex_32);
}
