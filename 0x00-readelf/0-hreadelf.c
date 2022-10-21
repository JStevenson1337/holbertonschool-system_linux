#include <hreadelf.h>

/**
 * print_ELF_header_info - prints ELF header table
 * @elf: elf_header_info_st struct
 **/
void print_ELF_header_info(Elf_hdr_info_t *elf)
{

	printf("ELF Header:\n");
	printf("  Magic:   7f 45 4c 46 %02x %02x %02x %02x %02x 00 00 00 00 00 00 00 \n", elf->class, elf->encoding, elf->version1, elf->os_abi, elf->abi_version);
	printf("  Class:                             ELF%u\n",                           32 * elf->class);
	printf("  Data:                              2's complement, %s endian\n",       elf->encoding == ELFDATA2MSB ? "big" : "little");
	printf("  Version:                           %u%s\n",                            elf->version1, elf->version1 == CURRENT_VERSION ? " (current)" : "");
	printf("  OS/ABI:                            %s\n",                              elf->os_abi_string);
	printf("  ABI Version:                       %u\n",                              elf->abi_version);
	printf("  Type:                              %s\n",                              elf->type_string);
	printf("  Machine:                           %s\n",                              elf->machine_string);
	printf("  Version:                           0x%x\n",                            elf->version2);
	printf("  Entry point address:               0x%lx\n",                           elf->entry);
	printf("  Start of program headers:          %lu (bytes into file)\n",           elf->phoff);
	printf("  Start of section headers:          %lu (bytes into file)\n",           elf->shoff);
	printf("  Flags:                             0x%x\n",                            elf->flags);
	printf("  Size of this header:               %u (bytes)\n",                      elf->ehsize);
	printf("  Size of program headers:           %u (bytes)\n",                      elf->phentsize);
	printf("  Number of program headers:         %u\n",                              elf->phnum);
	printf("  Size of section headers:           %u (bytes)\n",                      elf->shentsize);
	printf("  Number of section headers:         %u\n",                              elf->shnum);
	printf("  Section header string table index: %u\n",                              elf->shstrndx);
}

/**
 * get_ELF_os_abi_string - returns string describing OS/ABI value of ELF file
 * @os_abi: OS/ABI macro value (ELFOSABI_*)
 * Return: string
 **/
char *get_ELF_os_abi_string(uint8_t os_abi)
{
	char buf[64];

	switch (os_abi)
	{
	case ELFOSABI_SYSV:
		return (strdup("UNIX - System V"));
	case ELFOSABI_HPUX:
		return (strdup("HP-UX"));
	case ELFOSABI_NETBSD:
		return (strdup("UNIX - NetBSD"));
	case ELFOSABI_LINUX:
		return (strdup("Linux"));
	case ELFOSABI_SOLARIS:
		return (strdup("UNIX - Solaris"));
	case ELFOSABI_IRIX:
		return (strdup("IRIX"));
	case ELFOSABI_FREEBSD:
		return (strdup("FreeBSD"));
	case ELFOSABI_TRU64:
		return (strdup("TRU64 UNIX"));
	case ELFOSABI_ARM:
		return (strdup("ARM architecture"));
	case ELFOSABI_STANDALONE:
		return (strdup("Stand-alone (embedded) ABI"));
	}

	sprintf(buf, "<unknown: %x>", os_abi);
	return (strdup(buf));
}


/**
 * get_ELF_machine_string - returns string describing ELF machine type
 * @machine: ELF machine type macro (EM_*)
 * Return: string
 **/
char *get_ELF_machine_string(uint16_t machine)
{
	switch (machine)
	{
	case EM_M32:
		return (strdup("AT&T WE 32100"));
	case EM_SPARC:
		return (strdup("Sparc"));
	case EM_386:
		return (strdup("Intel 80386"));
	case EM_68K:
		return (strdup("Motorola 68000"));
	case EM_88K:
		return (strdup("Motorola 88000"));
	case EM_860:
		return (strdup("Intel 80860"));
	case EM_MIPS:
		return (strdup("MIPS RS3000"));
	case EM_PARISC:
		return (strdup("HP/PA"));
	case EM_SPARC32PLUS:
		return (strdup("SPARC with enhanced instruction set"));
	case EM_PPC:
		return (strdup("PowerPC"));
	case EM_PPC64:
		return (strdup("PowerPC 64-bit"));
	case EM_S390:
		return (strdup("IBM S/390"));
	case EM_ARM:
		return (strdup("Advanced RISC Machines"));
	case EM_SH:
		return (strdup("Renesas SuperH"));
	case EM_SPARCV9:
		return (strdup("SPARC v9 64-bit"));
	case EM_IA_64:
		return (strdup("Intel Itanium"));
	case EM_X86_64:
		return (strdup("Advanced Micro Devices X86-64"));
	case EM_VAX:
		return (strdup("DEC Vax"));
	}
	return (NULL);
}
