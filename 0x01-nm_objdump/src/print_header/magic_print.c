#include "../common_tools/common_tools.h"
#include "print_header.h"
/**
 * print_magic - prints the magic number of an ELF file
 * @e_ident: array of bytes in the ELF file
 *
 * Return: Nothing
 */
void print_magic(unsigned char e_ident[EI_NIDENT])
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%2.2x ", e_ident[i]);
	}
	printf("\n");
}
/**
 * print_class - prints the class of an ELF file
 * @class_flag: array of bytes in the ELF file
 *
 * Return: Nothing
 */
void print_class(unsigned char class_flag)
{
	char *value = NULL;

	printf("  Class:");
	print_spaces(29);
	switch (class_flag)
	{
		case ELFCLASSNONE:
			value = "none";
			break;
		case ELFCLASS32:
			value = "ELF32";
			break;
		case ELFCLASS64:
			value = "ELF64";
			break;
		default:
			value = NULL;
	}
	if (value)
		printf("%s\n", value);
	else
		printf("<unknown: %x>\n", class_flag);
}

/**
 * print_data - prints the data of an ELF file
 * @data_flag: flag to tell how data is structured in the file
 *
 * Return: Nothing
 */
void print_data(unsigned char data_flag)
{
	char *value = NULL;
	char *info = "  Data:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	switch (data_flag)
	{
	case ELFDATANONE:
		value = "none";
		break;
	case ELFDATA2LSB:
		value = "2's complement, little endian";
		break;
	case ELFDATA2MSB:
		value = "2's complement, big endian";
		break;
	}
	if (value)
		printf("%s\n", value);
	else
		printf("<unknown: %x>\n", data_flag);
}

/**
 * print_version - prints the version of an ELF file
 * @version_flag: flag to tell how data is structured in the file
 *
 * Return: Nothing
 */
void print_version(unsigned char version_flag)
{
	char *info = "  Version:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (version_flag == EV_CURRENT)
		printf("%d%s\n", version_flag, " (current)");
	else
		printf("%d%s\n", version_flag, " (invalid)");
}

/**
 * print_os - prints the os of an ELF file
 * @os_flag: the kind of os the file was created fot
 *
 * Return: Nothing
 */
void print_os(unsigned char os_flag)
{
	char *info = "  OS/ABI:";

	printf("%s", info);
	print_spaces(37 - strlen(info));
	if (get_osabi_name(os_flag))
		printf("%s\n", get_osabi_name(os_flag));
	else
		printf("<unknown: %x>\n", os_flag);
}
