#include <hreadelf.h>

#define SH_FIRST_ROW64 "  [Nr] Name              Type            Address          Off    Size   ES Flg Lk Inf Al\n"
#define SH_FIRST_ROW32 "  [Nr] Name              Type            Addr     Off    Size   ES Flg Lk Inf Al\n"
#define FLAG_KEY \
"\
Key to Flags:\n\
  W (write), A (alloc), X (execute), M (merge), S (strings), l (large)\n\
  I (info), L (link order), G (group), T (TLS), E (exclude), x (unknown)\n\
  O (extra OS processing required) o (OS specific), p (processor specific)\n\
"

/**
 * print_elf_section_header_table - parses ELF file; prints section header info
 * @fd: ELF file descriptor
 * @elf: pointer to Elf_hdr_info_t struct, used to navigate file
 **/
void print_elf_section_header_table(int fd, Elf_hdr_info_t *elf)
{
	char *string_table = get_string_table(fd, elf);
	uint16_t i;
	Elf64_Shdr *sh;

	printf("There are %d section headers, starting at offset 0x%lx:\n\n", elf->shnum, elf->shoff);
	printf("Section Headers:\n");
	printf(elf->class == ELFCLASS64 ? SH_FIRST_ROW64 : SH_FIRST_ROW32);
	lseek(fd, elf->shoff, SEEK_SET);
	for (i = 0; i < elf->shnum; i++)
	{
		sh = read_section_header(fd, elf->class, elf->encoding);
		printf("  [%2d] %-18s", i, string_table + sh->sh_name);
		print_sh_type(sh->sh_type);
		printf("%0*lx %06lx ", elf->class * 8, sh->sh_addr, sh->sh_offset);
		printf("%06lx %02lx ", sh->sh_size, sh->sh_entsize);
		print_sh_flags(sh->sh_flags);
		printf("%2u %3u %2lu\n", sh->sh_link, sh->sh_info, sh->sh_addralign);
	}
	printf(FLAG_KEY);
}

Elf64_Shdr *read_section_header(int fd, int class, int encoding)
{
	Elf64_Shdr *sh = calloc(1, sizeof(Elf64_Shdr));

	read_attr(fd, &sh->sh_name,      sizeof(sh->sh_name),  encoding);
	read_attr(fd, &sh->sh_type,      sizeof(sh->sh_type),  encoding);
	read_attr(fd, &sh->sh_flags,     sizeof(sh->sh_flags), encoding);
	read_attr(fd, &sh->sh_addr,      4 * class,            encoding);
	read_attr(fd, &sh->sh_offset,    4 * class,            encoding);
	read_attr(fd, &sh->sh_size,      4 * class,            encoding);
	read_attr(fd, &sh->sh_link,      sizeof(sh->sh_link),  encoding);
	read_attr(fd, &sh->sh_info,      sizeof(sh->sh_info),  encoding);
	read_attr(fd, &sh->sh_addralign, 4 * class,            encoding);
	read_attr(fd, &sh->sh_entsize,   4 * class,            encoding);
	return (sh);
}


/**
 * print_sh_flags - prints section header flags
 * @sh_flags: flags value
 **/
void print_sh_flags(uint32_t sh_flags)
{
	unsigned int j, k;
	char flag_string[16];
	macro_matcher_t flags[] = {
		{SHF_WRITE, "W"},
		{SHF_ALLOC, "A"},
		{SHF_EXECINSTR, "X"},
		{SHF_MERGE, "M"},
		{SHF_STRINGS, "S"},
		{SHF_INFO_LINK, "I"},
		{SHF_LINK_ORDER, "L"},
		{SHF_GROUP, "G"},
		{SHF_TLS, "T"},
		{SHF_EXCLUDE, "E"},
		{SHF_MASKOS, "o"},
		{SHF_MASKPROC, "O"}
	};

	for (j = 0, k = 0; j < sizeof(flags) / sizeof(macro_matcher_t); j++)
		if ((sh_flags & flags[j].macro) == flags[j].macro)
		{
			sprintf(flag_string + k++, "%s", flags[j].macro_string);
			sh_flags ^= flags[j].macro;
		}
	if (sh_flags)
		flag_string[k++] = 'x';
	flag_string[k] = '\0';
	printf("%3s ", flag_string);
}

/**
 * print_sh_type - prints sh_type info
 * @sh_type: sh_type value
 **/
void print_sh_type(uint32_t sh_type)
{
	macro_matcher_t types[] = {
		{SHT_PROGBITS, "PROGBITS"}, {SHT_SYMTAB, "SYMTAB"},
		{SHT_STRTAB, "STRTAB"}, {SHT_RELA, "RELA"},
		{SHT_HASH, "HASH"}, {SHT_DYNAMIC, "DYNAMIC"},
		{SHT_NOTE, "NOTE"}, {SHT_NOBITS, "NOBITS"},
		{SHT_REL, "REL"}, {SHT_SHLIB, "SHLIB"},
		{SHT_DYNSYM, "DYNSYM"}, {SHT_INIT_ARRAY, "INIT_ARRAY"},
		{SHT_FINI_ARRAY, "FINI_ARRAY"}, {SHT_PREINIT_ARRAY, "PREINIT_ARRAY"},
		{SHT_GROUP, "GROUP"}, {SHT_SYMTAB_SHNDX, "SYMTAB_SHNDX"},
		{SHT_LOOS, "LOOS"}, {SHT_GNU_ATTRIBUTES, "GNU_ATTRIBUTES"},
		{SHT_GNU_HASH, "GNU_HASH"}, {SHT_GNU_LIBLIST, "GNU_LIBLIST"},
		{SHT_CHECKSUM, "CHECKSUM"}, {SHT_LOSUNW, "LOSUNW"},
		{SHT_SUNW_move, "SUNW_move"}, {SHT_SUNW_COMDAT, "SUNW_COMDAT"},
		{SHT_SUNW_syminfo, "VERDEF"}, {SHT_GNU_verdef, "VERDEF"},
		{SHT_GNU_verneed, "VERNEED"}, {SHT_GNU_versym, "VERSYM"},
		{SHT_HISUNW, "HISUNW"}, {SHT_HIOS, "HIOS"},
		{SHT_LOPROC, "LOPROC"}, {SHT_HIPROC, "HIPROC"},
		{SHT_LOUSER, "LOUSER"}, {SHT_HIUSER, "HIUSER"}
	};
	int types_size = sizeof(types) / sizeof(macro_matcher_t), i;

	for (i = 0; i < types_size; i++)
		if (sh_type == (unsigned int)types[i].macro)
		{
			printf("%-15s ", types[i].macro_string);
			return;
		}
	if (sh_type)
		printf("LOOS+%x    ", sh_type & 0xfffffff);
	else
		printf("NULL            ");
}
