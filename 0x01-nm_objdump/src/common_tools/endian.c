#include "common_tools.h"
/**
 * endian_check - checks the endianess of the headers to understand the data
 * @header: address of the 64 bits structure
 * @header_32: address of the 32 bits structure
 */
void endian_check(Elf64_Ehdr *header, Elf32_Ehdr *header_32)
{
	if (header->e_ident[5] == 2)
	/*64 bits system*/
	{
		header->e_machine = __bswap_constant_16(header->e_machine);
		header->e_version = __bswap_constant_32(header->e_version);
		if (header->e_ident[4] == 2)
		/* big endian*/
		{
			header->e_entry = __bswap_constant_64(header->e_entry);
			header->e_phoff = __bswap_constant_64(header->e_phoff);
			header->e_shoff = __bswap_constant_64(header->e_shoff);
			header->e_ehsize = __bswap_constant_16(header->e_ehsize);
			header->e_phentsize = __bswap_constant_16(header->e_phentsize);
			header->e_phnum = __bswap_constant_16(header->e_phnum);
			header->e_shentsize = __bswap_constant_16(header->e_shentsize);
			header->e_shnum = __bswap_constant_16(header->e_shnum);
			header->e_shstrndx = __bswap_constant_16(header->e_shstrndx);
			header->e_type = __bswap_constant_16(header->e_type);
		}
		else
		{
			header_32->e_entry = __bswap_constant_32(header_32->e_entry);
			header_32->e_phoff = __bswap_constant_32(header_32->e_phoff);
			header_32->e_shoff = __bswap_constant_32(header_32->e_shoff);
			header_32->e_flags = __bswap_constant_32(header_32->e_flags);
			header_32->e_ehsize = __bswap_constant_16(header_32->e_ehsize);
			header_32->e_phentsize = __bswap_constant_16(header_32->e_phentsize);
			header_32->e_phnum = __bswap_constant_16(header_32->e_phnum);
			header_32->e_shentsize = __bswap_constant_16(header_32->e_shentsize);
			header_32->e_shnum = __bswap_constant_16(header_32->e_shnum);
			header_32->e_shstrndx = __bswap_constant_16(header_32->e_shstrndx);
			header_32->e_type = __bswap_constant_16(header_32->e_type);
		}
	}
}
