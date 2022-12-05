#include "../common_tools/common_tools.h"
#include "print_header.h"
/**
 * get_osabi_name - helper function to ovtain the name of the machine
 *
 * @osabi: osabi flag used to obtain the information
 *
 * Return: The string with the desired value
 */
char *get_osabi_name(unsigned int osabi)
{

	switch (osabi)
	{
		case ELFOSABI_NONE:		return ("UNIX - System V");
		case ELFOSABI_HPUX:		return ("UNIX - HP-UX");
		case ELFOSABI_NETBSD:	return ("UNIX - NetBSD");
		case ELFOSABI_GNU:		return ("UNIX - GNU");
		case ELFOSABI_SOLARIS:	return ("UNIX - Solaris");
		case ELFOSABI_AIX:		return ("UNIX - AIX");
		case ELFOSABI_IRIX:		return ("UNIX - IRIX");
		case ELFOSABI_FREEBSD:	return ("UNIX - FreeBSD");
		case ELFOSABI_TRU64:	return ("UNIX - TRU64");
		case ELFOSABI_MODESTO:	return ("Novell - Modesto");
		case ELFOSABI_OPENBSD:	return ("UNIX - OpenBSD");
		default:
		return (NULL);
	}
}

/**
 * get_file_type - helper function to ovtain the name of the machine
 *
 * @e_type: osabi flag used to obtain the information
 *
 * Return: The string with the desired value
 */
char *get_file_type(unsigned int e_type)
{
	static char buff[64];

	switch (e_type)
	{
		case ET_NONE: return ("NONE (None)");
		case ET_REL:  return ("REL (Relocatable file)");
		case ET_EXEC: return ("EXEC (Executable file)");
		case ET_DYN:  return ("DYN (Shared object file)");
		case ET_CORE: return ("CORE (Core file)");
		default:
			if ((e_type >= ET_LOPROC) && (e_type <= ET_HIPROC))
				snprintf(buff, sizeof(buff), "Processor Specific: (%x)", e_type);
			else if ((e_type >= ET_LOOS) && (e_type <= ET_HIOS))
				snprintf(buff, sizeof(buff), "OS Specific: (%x)", e_type);
			else
				snprintf(buff, sizeof(buff), "<unknown>: %x", e_type);
			return (buff);
	}
}
