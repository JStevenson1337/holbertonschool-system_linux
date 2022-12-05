#include "common_tools.h"

#define NO_ELF "readelf: Error: Not an ELF file"
#define WRONG_MAGIC "- it has the wrong magic bytes at the start\n"
#define DIRECTORY "readelf: Error: '%s' is not an ordinary file\n"
#define NOPERM "readelf: Error: Input file '%s' is not readable\n"
#define NOFILE "readelf: Error: '%s': No such file\n"

/**
 *read_elf_header - opens the binary file and return the header structure
 *@file: pointer to the file to be opened
 *@file_name: name of the file that's going to be opened
 *@header_32: pointer to the 32 bit structure version
 *
 *Return: pointer to the 64 bits structure version
 */
Elf64_Ehdr read_elf_header(FILE **file, char *file_name, Elf32_Ehdr *header_32)
{
	struct stat sb;
	Elf64_Ehdr header;

	if ((stat(file_name, &sb) == 0) && ((sb.st_mode & S_IFMT) == S_IFDIR))
	{
		fprintf(stderr, DIRECTORY, file_name);
		exit(1);
	}
	else if (stat(file_name, &sb) == 0 && access(file_name, R_OK) != 0)
	{
		fprintf(stderr, NOPERM, file_name);
		exit(1);
	}
	else if (stat(file_name, &sb) != 0)
	{
		fprintf(stderr, NOFILE, file_name);
		exit(1);
	}
	*file = fopen(file_name, "rb");
	if (*file)
	{
		fread(&header, sizeof(header), 1, *file);
		rewind(*file);
		fread(header_32, sizeof(*header_32), 1, *file);
		if (memcmp(header.e_ident, ELFMAG, SELFMAG) == 0)
		{
			return (header);
		}
		fprintf(stderr, "%s %s", NO_ELF, WRONG_MAGIC);
		exit(1);
	}
	else
	{
		exit(1);
	}
}
