#include <hreadelf.h>

static char *get_string_table64(int ELF_fd, int offset, int encoding);
static char *get_string_table32(int ELF_fd, int offset, int encoding);
static unsigned char open_ELF(int *ELF_fd, char *ELF_name, char *program);

#define strindex(h) (h.e_shoff + (h.e_shentsize * h.e_shstrndx))

/**
 * main - replica of readelf -W -h <file>, where <file> is argv[1]
 * @argc: argument count
 * @argv: argument array
 * Return: 0 on success or no arguments passed | 1 on failure
 **/
int main(int argc, char *argv[])
{
	int ELF_fd;

	if (argc > 1)
	{
		if (open_ELF(&ELF_fd, argv[1], "readelf") == ELFCLASS64)
			print_elf64_program_header_table(ELF_fd);
		else
			print_elf32_program_header_table(ELF_fd);
	}

	return (EXIT_SUCCESS);
}

/**
 * print_elf64_program_header_table - prints ELF64 section header table
 * @ELF_fd: ELF file descriptor
 * Return: irrelevant
 **/
int print_elf64_program_header_table(int ELF_fd)
{
	Elf64_Ehdr h;
	Elf64_Phdr ph;
	unsigned int i, j;
	char *st, tmp[512];
	uint64_t paddrs[5125], fileszs[512];

	read(ELF_fd, &h, sizeof(h));
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		lseek(ELF_fd, 0, 0), read_elf64_header_MSB(&h, ELF_fd);
	if (h.e_phnum == 0)
		return (printf("\nThere are no program headers in this file.\n"));
	printf("\nElf file type is "), print_elf_file_type(h.e_type);
	printf("Entry point 0x%x\n", (unsigned int)h.e_entry);
	printf(PH_SUMMARY, h.e_phnum, (int)h.e_phoff), puts(PH_INTRO);
	puts(PH_FIRST_ROW), lseek(ELF_fd, h.e_phoff, 0);
	for (i = 0; i < h.e_phnum; i++)
	{
		if (h.e_ident[EI_DATA] == ELFDATA2MSB)
			read_elf64_program_MSB(&ph, ELF_fd);
		else
			read(ELF_fd, &ph, sizeof(ph));
		paddrs[i] = ph.p_paddr, fileszs[i] = ph.p_filesz;
		if (print_ELF64_program_header_row(ph) == IS_INTERP_ROW)
		{
			lseek(ELF_fd, ph.p_offset, 0), read(ELF_fd, tmp, ph.p_filesz);
			printf("      [Requesting program interpreter: %s]\n", tmp);
			lseek(ELF_fd, h.e_phoff + ((i + 1) * h.e_phentsize), 0);
		}
	}
	puts("\n Section to Segment mapping:\n  Segment Sections...");
	st = get_string_table64(ELF_fd, strindex(h), h.e_ident[EI_DATA]);
	for (i = 0, j = 0; i < h.e_phnum; printf("\n"), i++)
	{
		lseek(ELF_fd, h.e_shoff, 0), printf("   %02d     ", i);
		for (j = 0; j < h.e_shnum; j++)
			print_segment64(ELF_fd, paddrs[i], fileszs[i], st);
	}
	free(st);
	return (0);
}


/**
 * print_elf32_program_header_table - prints ELF32 section header table
 * @ELF_fd: ELF file descriptor
 * Return: irrelevant
 **/
int print_elf32_program_header_table(int ELF_fd)
{
	Elf32_Ehdr h;
	Elf32_Phdr ph;
	unsigned int i, j;
	char *st, tmp[512];
	uint32_t paddrs[512], fileszs[512];

	read(ELF_fd, &h, sizeof(h));
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		lseek(ELF_fd, 0, 0), read_elf32_header_MSB(&h, ELF_fd);
	if (h.e_phnum == 0)
		return (printf("\nThere are no program headers in this file.\n"));
	printf("\nElf file type is "), print_elf_file_type(h.e_type);
	printf("Entry point 0x%x\n", (unsigned int)h.e_entry);
	printf(PH_SUMMARY, h.e_phnum, (int)h.e_phoff);
	puts(PH_INTRO), puts(PH_FIRST_ROW32), lseek(ELF_fd, h.e_phoff, 0);
	for (i = 0; i < h.e_phnum; i++)
	{
		if (h.e_ident[EI_DATA] == ELFDATA2MSB)
			read_elf32_program_MSB(&ph, ELF_fd);
		else
			read(ELF_fd, &ph, sizeof(ph));
		paddrs[i] = ph.p_paddr, fileszs[i] = ph.p_filesz;
		if (print_ELF32_program_header_row(ph) == IS_INTERP_ROW)
		{
			lseek(ELF_fd, ph.p_offset, 0), read(ELF_fd, tmp, ph.p_filesz);
			printf("      [Requesting program interpreter: %s]\n", tmp);
			lseek(ELF_fd, h.e_phoff + ((i + 1) * h.e_phentsize), 0);
		}
	}
	puts("\n Section to Segment mapping:\n  Segment Sections...");
	st = get_string_table32(ELF_fd, strindex(h), h.e_ident[EI_DATA]);
	for (i = 0, j = 0; i < h.e_phnum; printf("\n"), i++)
	{
		lseek(ELF_fd, h.e_shoff, 0), printf("   %02d     ", i);
		for (j = 0; j < h.e_shnum; j++)
			print_segment64(ELF_fd, paddrs[i], fileszs[i], st);
	}
	free(st);
	return (0);
}

/**
 * print_ELF32_program_header_row - prints one row of a program header table
 * @ph: program header struct
 * Return: 0 almost alsways | 1 if program header is of type "INTERP"
 **/
int print_ELF32_program_header_row(Elf32_Phdr ph)
{
	int flag;

	flag = print_p_type(ph.p_type);
	printf("0x%06x ",  (unsigned int)ph.p_offset);
	printf("0x%08x ", (unsigned int)ph.p_vaddr);
	printf("0x%08x ", (unsigned int)ph.p_paddr);
	printf("0x%05x ",  (unsigned int)ph.p_filesz);
	printf("0x%05x ",  (unsigned int)ph.p_memsz);
	print_p_flags(ph.p_flags);
	printf("%#x\n",   (unsigned int)ph.p_align);
	return (flag);
}

/**
 * print_ELF64_program_header_row - prints one row of a program header table
 * @ph: program header struct
 * Return: 0 almost alsways | 1 if program header is of type "INTERP"
 **/
int print_ELF64_program_header_row(Elf64_Phdr ph)
{
	int flag;

	flag = print_p_type(ph.p_type);
	printf("0x%06x ",  (unsigned int)ph.p_offset);
	printf("0x%016x ", (unsigned int)ph.p_vaddr);
	printf("0x%016x ", (unsigned int)ph.p_paddr);
	printf("0x%06x ",  (unsigned int)ph.p_filesz);
	printf("0x%06x ",  (unsigned int)ph.p_memsz);
	print_p_flags(ph.p_flags);
	printf("0x%x\n",   (unsigned int)ph.p_align);
	return (flag);
}

/**
 * open_ELF - opens ELF file
 * @ELF_fd: pointer where ELF file descriptor will be stored
 * @ELF_name: ELF file name
 * @program: program attempting to open ELF file
 * Return: ELF file class
 **/
static unsigned char open_ELF(int *ELF_fd, char *ELF_name, char *program)
{
	unsigned char elf_identity[EI_NIDENT];
	Elf32_Ehdr h32;
	Elf64_Ehdr h64;

	*ELF_fd = open(ELF_name, O_RDONLY);
	if (*ELF_fd <= 0)
	{
		fprintf(stderr, "%s: Error: '%s': No such file\n", program, ELF_name);
		exit(EXIT_FAILURE);
	}
	if (read(*ELF_fd, &elf_identity, EI_NIDENT) < EI_NIDENT)
	{
		fprintf(stderr, "%s: Error: %s: Failed to read file's magic number\n",
				program, ELF_name);
		close(*ELF_fd), exit(EXIT_FAILURE);
	}
	if (memcmp(ELFMAG, elf_identity, SELFMAG))
	{
		fprintf(stderr, "%s: Error: Not an ELF file -", program);
		fprintf(stderr, " it has the wrong magic bytes at the start\n");
		close(*ELF_fd), exit(EXIT_FAILURE);
	}
	lseek(*ELF_fd, 0, 0);
	if (elf_identity[EI_CLASS] == ELFCLASS32)
	{
		if (read(*ELF_fd, &h32, sizeof(h32) != sizeof(h32)))
		{
			fprintf(stderr, "%s: Error: %s: ", program, ELF_name);
			fprintf(stderr, "Failed to read file header\n");
			close(*ELF_fd), exit(EXIT_FAILURE);
		}
	}
	else if (read(*ELF_fd, &h64, sizeof(h64)) != sizeof(h64))
	{
		fprintf(stderr, "%s: Error: %s: ", program, ELF_name);
		fprintf(stderr, "Failed to read file header\n");
		close(*ELF_fd), exit(EXIT_FAILURE);
	}
	lseek(*ELF_fd, 0, 0);
	return (elf_identity[EI_CLASS]);
}


/**
 * read_elf64_header_MSB - fills in an Elf64 header using MSB encoding
 * @h: pointer to header struct
 * @fd: file descriptor
 **/
void read_elf64_header_MSB(Elf64_Ehdr *h, int fd)
{
	unsigned char i, j;

	read(fd, &(h->e_ident), sizeof(h->e_ident));

	for (j = 0; j < sizeof(h->e_type)     ; j++)
		read(fd, &i, 1), h->e_type      = (h->e_type      << 8) + i;
	for (j = 0; j < sizeof(h->e_machine)  ; j++)
		read(fd, &i, 1), h->e_machine   = (h->e_machine   << 8) + i;
	for (j = 0; j < sizeof(h->e_version)  ; j++)
		read(fd, &i, 1), h->e_version   = (h->e_version   << 8) + i;
	for (j = 0; j < sizeof(h->e_entry)    ; j++)
		read(fd, &i, 1), h->e_entry     = (h->e_entry     << 8) + i;
	for (j = 0; j < sizeof(h->e_phoff)    ; j++)
		read(fd, &i, 1), h->e_phoff     = (h->e_phoff     << 8) + i;
	for (j = 0; j < sizeof(h->e_shoff)    ; j++)
		read(fd, &i, 1), h->e_shoff     = (h->e_shoff     << 8) + i;
	for (j = 0; j < sizeof(h->e_flags)    ; j++)
		read(fd, &i, 1), h->e_flags     = (h->e_flags     << 8) + i;
	for (j = 0; j < sizeof(h->e_ehsize)   ; j++)
		read(fd, &i, 1), h->e_ehsize    = (h->e_ehsize    << 8) + i;
	for (j = 0; j < sizeof(h->e_phentsize); j++)
		read(fd, &i, 1), h->e_phentsize = (h->e_phentsize << 8) + i;
	for (j = 0; j < sizeof(h->e_phnum)    ; j++)
		read(fd, &i, 1), h->e_phnum     = (h->e_phnum     << 8) + i;
	for (j = 0; j < sizeof(h->e_shentsize); j++)
		read(fd, &i, 1), h->e_shentsize = (h->e_shentsize << 8) + i;
	for (j = 0; j < sizeof(h->e_shnum)    ; j++)
		read(fd, &i, 1), h->e_shnum     = (h->e_shnum     << 8) + i;
	for (j = 0; j < sizeof(h->e_shstrndx) ; j++)
		read(fd, &i, 1), h->e_shstrndx  = (h->e_shstrndx  << 8) + i;
}

/**
 * read_elf32_header_MSB - fills in an Elf32 header using MSB encoding
 * @h: pointer to header struct
 * @fd: file descriptor
 **/
void read_elf32_header_MSB(Elf32_Ehdr *h, int fd)
{
	unsigned char i, j;

	read(fd, &(h->e_ident), sizeof(h->e_ident));

	for (j = 0; j < sizeof(h->e_type)     ; j++)
		read(fd, &i, 1), h->e_type      = (h->e_type      << 8) + i;
	for (j = 0; j < sizeof(h->e_machine)  ; j++)
		read(fd, &i, 1), h->e_machine   = (h->e_machine   << 8) + i;
	for (j = 0; j < sizeof(h->e_version)  ; j++)
		read(fd, &i, 1), h->e_version   = (h->e_version   << 8) + i;
	for (j = 0; j < sizeof(h->e_entry)    ; j++)
		read(fd, &i, 1), h->e_entry     = (h->e_entry     << 8) + i;
	for (j = 0; j < sizeof(h->e_phoff)    ; j++)
		read(fd, &i, 1), h->e_phoff     = (h->e_phoff     << 8) + i;
	for (j = 0; j < sizeof(h->e_shoff)    ; j++)
		read(fd, &i, 1), h->e_shoff     = (h->e_shoff     << 8) + i;
	for (j = 0; j < sizeof(h->e_flags)    ; j++)
		read(fd, &i, 1), h->e_flags     = (h->e_flags     << 8) + i;
	for (j = 0; j < sizeof(h->e_ehsize)   ; j++)
		read(fd, &i, 1), h->e_ehsize    = (h->e_ehsize    << 8) + i;
	for (j = 0; j < sizeof(h->e_phentsize); j++)
		read(fd, &i, 1), h->e_phentsize = (h->e_phentsize << 8) + i;
	for (j = 0; j < sizeof(h->e_phnum)    ; j++)
		read(fd, &i, 1), h->e_phnum     = (h->e_phnum     << 8) + i;
	for (j = 0; j < sizeof(h->e_shentsize); j++)
		read(fd, &i, 1), h->e_shentsize = (h->e_shentsize << 8) + i;
	for (j = 0; j < sizeof(h->e_shnum)    ; j++)
		read(fd, &i, 1), h->e_shnum     = (h->e_shnum     << 8) + i;
	for (j = 0; j < sizeof(h->e_shstrndx) ; j++)
		read(fd, &i, 1), h->e_shstrndx  = (h->e_shstrndx  << 8) + i;
}


/**
 * read_elf32_section_MSB - fills in an Elf32 header using MSB encoding
 * @h: pointer to header struct
 * @fd: file descriptor
 **/
void read_elf32_section_MSB(Elf32_Shdr *h, int fd)
{
	unsigned char i, j;

	for (j = 0; j < sizeof(h->sh_name)     ; j++)
		read(fd, &i, 1), h->sh_name        = (h->sh_name      << 8) + i;
	for (j = 0; j < sizeof(h->sh_type)     ; j++)
		read(fd, &i, 1), h->sh_type        = (h->sh_type      << 8) + i;
	for (j = 0; j < sizeof(h->sh_flags)    ; j++)
		read(fd, &i, 1), h->sh_flags       = (h->sh_flags     << 8) + i;
	for (j = 0; j < sizeof(h->sh_addr)     ; j++)
		read(fd, &i, 1), h->sh_addr        = (h->sh_addr      << 8) + i;
	for (j = 0; j < sizeof(h->sh_offset)   ; j++)
		read(fd, &i, 1), h->sh_offset      = (h->sh_offset    << 8) + i;
	for (j = 0; j < sizeof(h->sh_size)     ; j++)
		read(fd, &i, 1), h->sh_size        = (h->sh_size      << 8) + i;
	for (j = 0; j < sizeof(h->sh_link)     ; j++)
		read(fd, &i, 1), h->sh_link        = (h->sh_link      << 8) + i;
	for (j = 0; j < sizeof(h->sh_info)     ; j++)
		read(fd, &i, 1), h->sh_info        = (h->sh_info      << 8) + i;
	for (j = 0; j < sizeof(h->sh_addralign); j++)
		read(fd, &i, 1), h->sh_addralign   = (h->sh_addralign << 8) + i;
	for (j = 0; j < sizeof(h->sh_entsize)  ; j++)
		read(fd, &i, 1), h->sh_entsize     = (h->sh_entsize   << 8) + i;
}

/**
 * read_elf64_section_MSB - fills in an Elf32 header using MSB encoding
 * @h: pointer to header struct
 * @fd: file descriptor
 **/
void read_elf64_section_MSB(Elf64_Shdr *h, int fd)
{
	unsigned char i, j;

	for (j = 0; j < sizeof(h->sh_name)     ; j++)
		read(fd, &i, 1), h->sh_name        = (h->sh_name      << 8) + i;
	for (j = 0; j < sizeof(h->sh_type)     ; j++)
		read(fd, &i, 1), h->sh_type        = (h->sh_type      << 8) + i;
	for (j = 0; j < sizeof(h->sh_flags)    ; j++)
		read(fd, &i, 1), h->sh_flags       = (h->sh_flags     << 8) + i;
	for (j = 0; j < sizeof(h->sh_addr)     ; j++)
		read(fd, &i, 1), h->sh_addr        = (h->sh_addr      << 8) + i;
	for (j = 0; j < sizeof(h->sh_offset)   ; j++)
		read(fd, &i, 1), h->sh_offset      = (h->sh_offset    << 8) + i;
	for (j = 0; j < sizeof(h->sh_size)     ; j++)
		read(fd, &i, 1), h->sh_size        = (h->sh_size      << 8) + i;
	for (j = 0; j < sizeof(h->sh_link)     ; j++)
		read(fd, &i, 1), h->sh_link        = (h->sh_link      << 8) + i;
	for (j = 0; j < sizeof(h->sh_info)     ; j++)
		read(fd, &i, 1), h->sh_info        = (h->sh_info      << 8) + i;
	for (j = 0; j < sizeof(h->sh_addralign); j++)
		read(fd, &i, 1), h->sh_addralign   = (h->sh_addralign << 8) + i;
	for (j = 0; j < sizeof(h->sh_entsize)  ; j++)
		read(fd, &i, 1), h->sh_entsize     = (h->sh_entsize   << 8) + i;
}

/**
 * get_string_table64 - returns alloc'd buffer of an ELF string table
 * @ELF_fd: ELF file descriptor
 * @offset: byte offset where string table begins
 * @encoding: data encoding type (either ELFDATA2MSB or ELFDATA2LSB)
 * Return: pointer to alloc'd buffer contiaining string table contents
 **/
static char *get_string_table64(int ELF_fd, int offset, int encoding)
{
	char *string_table;
	Elf64_Shdr s_h;

	lseek(ELF_fd, offset, 0);
	if (encoding == ELFDATA2MSB)
		read_elf64_section_MSB(&s_h, ELF_fd);
	else
		read(ELF_fd, &s_h, sizeof(s_h));
	string_table = malloc(sizeof(char) * s_h.sh_size);
	lseek(ELF_fd, s_h.sh_offset, 0);
	read(ELF_fd, string_table, s_h.sh_size);
	lseek(ELF_fd, 0, 0);
	return (string_table);
}

/**
 * get_string_table32 - returns alloc'd buffer of an ELF string table
 * @ELF_fd: ELF file descriptor
 * @offset: byte offset where string table begins
 * @encoding: data encoding type (either ELFDATA2MSB or ELFDATA2LSB)
 * Return: pointer to alloc'd buffer contiaining string table contents
 **/
static char *get_string_table32(int ELF_fd, int offset, int encoding)
{
	char *string_table;
	Elf32_Shdr s_h;

	lseek(ELF_fd, offset, 0);
	if (encoding == ELFDATA2MSB)
		read_elf32_section_MSB(&s_h, ELF_fd);
	else
		read(ELF_fd, &s_h, sizeof(s_h));
	string_table = malloc(sizeof(char) * s_h.sh_size);
	lseek(ELF_fd, s_h.sh_offset, 0);
	read(ELF_fd, string_table, s_h.sh_size);
	lseek(ELF_fd, 0, 0);
	return (string_table);
}

/**
 * print_elf_file_type - prints ELF file type
 * @e_type: ELF header e_type value
 **/
void print_elf_file_type(uint16_t e_type)
{
	macro_matcher_t types[] = {
		{ET_NONE, "NONE (Unknown type)"},
		{ET_REL, "REL (Relocatable file)"},
		{ET_EXEC, "EXEC (Executable file)"},
		{ET_DYN, "DYN (Shared object file)"},
		{ET_CORE, "CORE (Core file)"}
	};
	unsigned int i;

	for (i = 0; i < sizeof(types) / sizeof(macro_matcher_t); i++)
	{
		if (types[i].macro == e_type)
		{
			puts(types[i].macro_string);
			return;
		}
	}

	printf("<unknown: %u %x>\n", e_type, e_type);

}


/**
 * print_segment64 - prints segment info for ELF program header table
 * @ELF_fd: ELF file descriptor
 * @paddr: current segment physical addr
 * @filesz: current segment file size
 * @st: string table
 **/
void print_segment64(int ELF_fd, Elf64_Addr paddr, uint64_t filesz, char *st)
{
	Elf64_Shdr sh;

	read(ELF_fd, &sh, sizeof(sh));
	if (sh.sh_addr >= paddr && sh.sh_addr < paddr + filesz)
	{
		if (printf("%s", st + sh.sh_name))
			putchar(' ');
		if (!strcmp(".data", st + sh.sh_name))
			printf(".bss ");
	}
}

/**
 * print_segment32 - prints segment info for ELF program header table
 * @ELF_fd: ELF file descriptor
 * @paddr: current segment physical addr
 * @filesz: current segment file size
 * @st: string table
 **/
void print_segment32(int ELF_fd, Elf32_Addr paddr, uint32_t filesz, char *st)
{
	Elf32_Shdr sh;

	read(ELF_fd, &sh, sizeof(sh));
	if (sh.sh_addr >= paddr && sh.sh_addr < paddr + filesz)
	{
		if (printf("%s", st + sh.sh_name))
			putchar(' ');
		if (!strcmp(".data", st + sh.sh_name))
			printf(".bss ");
	}
}

/**
 * print_p_flags - prints section header flags
 * @p_flags: flags value
 **/
void print_p_flags(uint32_t p_flags)
{
	unsigned int j, k;
	char flag_string[16];
	macro_matcher_t flags[] = {
		{PF_R, "R"},
		{PF_W, "W"},
		{PF_X, "E"}
	};

	for (j = 0, k = 0; j < sizeof(flags) / sizeof(macro_matcher_t); j++, k++)
		if (p_flags & flags[j].macro)
		{
			sprintf(flag_string + k, "%s", flags[j].macro_string);
			p_flags ^= flags[j].macro;
		}
		else
		{
			flag_string[k] = ' ';
		}
	flag_string[k] = '\0';
	printf("%3s ", flag_string);
}


/**
 * print_p_type - prints p_type info
 * @p_type: p_type value
 * Return: 1 if INTERP | 0 if not
 **/
int print_p_type(uint32_t p_type)
{
	macro_matcher_t types[] = {
		{PT_LOAD, "LOAD"},
		{PT_DYNAMIC, "DYNAMIC"},
		{PT_INTERP, "INTERP"},
		{PT_NOTE, "NOTE"},
		{PT_SHLIB, "SHLIB"},
		{PT_PHDR, "PHDR"},
		{PT_TLS, "TLS"},
		{PT_LOOS, "LOOS"},
		{PT_GNU_EH_FRAME, "GNU_EH_FRAME"},
		{PT_GNU_STACK, "GNU_STACK"},
		{PT_GNU_RELRO, "GNU_RELRO"},
		{PT_LOSUNW, "LOSUNW"},
		{PT_SUNWBSS, "SUNWBSS"},
		{PT_SUNWSTACK, "SUNWSTACK"},
		{PT_HISUNW, "HISUNW"},
		{PT_HIOS, "HIOS"},
		{PT_LOPROC, "LOPROC"},
		{PT_HIPROC, "HIPROC"}
		};

	int types_size = sizeof(types) / sizeof(macro_matcher_t), i;

	for (i = 0; i < types_size && p_type != (unsigned int)types[i].macro; i++)
		;

	printf("  %-14s ", i == types_size ? "NULL" : types[i].macro_string);
	return (types[i].macro == PT_INTERP);
}

/**
 * read_elf32_program_MSB - fills in an Elf32 header using MSB encoding
 * @h: pointer to header struct
 * @fd: file descriptor
 **/
void read_elf32_program_MSB(Elf32_Phdr *h, int fd)
{
	unsigned char i, j;

	for (j = 0; j < sizeof(h->p_type); j++)
		read(fd, &i, 1), h->p_type   = (h->p_type   << 8) + i;

	for (j = 0; j < sizeof(h->p_offset); j++)
		read(fd, &i, 1), h->p_offset = (h->p_offset << 8) + i;

	for (j = 0; j < sizeof(h->p_vaddr) ; j++)
		read(fd, &i, 1), h->p_vaddr  = (h->p_vaddr  << 8) + i;

	for (j = 0; j < sizeof(h->p_paddr) ; j++)
		read(fd, &i, 1), h->p_paddr  = (h->p_paddr  << 8) + i;

	for (j = 0; j < sizeof(h->p_filesz); j++)
		read(fd, &i, 1), h->p_filesz = (h->p_filesz << 8) + i;

	for (j = 0; j < sizeof(h->p_memsz) ; j++)
		read(fd, &i, 1), h->p_memsz  = (h->p_memsz  << 8) + i;

	for (j = 0; j < sizeof(h->p_flags) ; j++)
		read(fd, &i, 1), h->p_flags  = (h->p_flags  << 8) + i;

	for (j = 0; j < sizeof(h->p_align) ; j++)
		read(fd, &i, 1), h->p_align  = (h->p_align  << 8) + i;

}

/**
 * read_elf64_program_MSB - fills in an Elf32 header using MSB encoding
 * @h: pointer to header struct
 * @fd: file descriptor
 **/
void read_elf64_program_MSB(Elf64_Phdr *h, int fd)
{
	unsigned char i, j;

	for (j = 0; j < sizeof(h->p_type)  ; j++)
		read(fd, &i, 1), h->p_type   = (h->p_type   << 8) + i;

	for (j = 0; j < sizeof(h->p_offset); j++)
		read(fd, &i, 1), h->p_offset = (h->p_offset << 8) + i;

	for (j = 0; j < sizeof(h->p_vaddr) ; j++)
		read(fd, &i, 1), h->p_vaddr  = (h->p_vaddr     << 8) + i;

	for (j = 0; j < sizeof(h->p_paddr) ; j++)
		read(fd, &i, 1), h->p_paddr  = (h->p_paddr     << 8) + i;

	for (j = 0; j < sizeof(h->p_filesz); j++)
		read(fd, &i, 1), h->p_filesz = (h->p_filesz    << 8) + i;

	for (j = 0; j < sizeof(h->p_memsz) ; j++)
		read(fd, &i, 1), h->p_memsz  = (h->p_memsz     << 8) + i;

	for (j = 0; j < sizeof(h->p_flags) ; j++)
		read(fd, &i, 1), h->p_flags  = (h->p_flags     << 8) + i;

	for (j = 0; j < sizeof(h->p_align) ; j++)
		read(fd, &i, 1), h->p_align  = (h->p_align     << 8) + i;

}
