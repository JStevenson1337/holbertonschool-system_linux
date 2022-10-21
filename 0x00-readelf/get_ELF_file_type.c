#include <hreadelf.h>


/**
 * get_ELF_type_string - returns string describing an ELF file type
 * @type: ELF file type macro (ET_*)
 * Return: string
 **/
char *get_ELF_type_string(uint16_t type)
{
	switch (type)
	{
	case ET_NONE:
		return (strdup("NONE (Unknown type)"));
	case ET_REL:
		return (strdup("REL (Relocatable file)"));
	case ET_EXEC:
		return (strdup("EXEC (Executable file)"));
	case ET_DYN:
		return (strdup("DYN (Shared object file)"));
	case ET_CORE:
		return (strdup("CORE (Core file)"));
	}

	return (NULL);
}
