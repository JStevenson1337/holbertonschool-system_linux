#include "../common_tools/common_tools.h"
#include "print_header.h"
/**
 * print_version2 - prints the flags number of an ELF file
 * @version: array of bytes in the ELF file
 *
 * Return: Nothing
 */
void print_version2(Elf64_Word version)
{
	char *info = "  Version:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	printf("0x%x\n", version);
}

/**
 * print_entryp - prints the entryp number of an ELF file
 * @entryp: array of bytes in the ELF file
 * @entryp_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_entryp(Elf64_Addr entryp, Elf32_Addr entryp_32, int selector)
{
	char *info = "  Entry point address:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("0x%lx\n", entryp);
	else
		printf("0x%x\n", entryp_32);
}

/**
 * print_proghead - prints the proghead number of an ELF file
 * @proghead: array of bytes in the ELF file
 * @proghead_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_proghead(Elf64_Addr proghead, Elf32_Addr proghead_32, int selector)
{
	char *info = "  Start of program headers:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("%lu (bytes into file)\n", proghead);
	else
		printf("%d (bytes into file)\n", proghead_32);
}

/**
 * print_sechead - prints the sechead number of an ELF file
 * @sechead: array of bytes in the ELF file
 * @sechead_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_sechead(Elf64_Addr sechead, Elf32_Addr sechead_32, int selector)
{
	char *info = "  Start of section headers:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("%lu (bytes into file)\n", sechead);
	else
		printf("%d (bytes into file)\n", sechead_32);
}

/**
 * print_flags - prints the flags number of an ELF file
 * @flags: array of bytes in the ELF file
 * @flags_32: array of bytes in the ELF file 32 bit version
 * @selector: flag to handle 32 bits or 64 bits
 *
 * Return: Nothing
 */
void print_flags(Elf64_Word flags, Elf32_Word flags_32, int selector)
{
	char *info = "  Flags:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (selector == 2)
		printf("0x%x\n", flags);
	else
		printf("0x%x\n", flags_32);

}
