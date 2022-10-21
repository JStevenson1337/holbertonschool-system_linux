#include <hreadelf.h>

static void free_elf_info(Elf_hdr_info_t *elf);
static Elf_hdr_info_t *read_elf_header(int fd);

/**
 * main - replica of readelf -W -h <file>, where <file> is argv[1]
 * @argc: argument count
 * @argv: argument array
 * Return: 0 on success or no arguments passed | 1 on failure
 **/
int main(int argc, char *argv[])
{
	unsigned char magic_number[SELFMAG];
	Elf_hdr_info_t *elf;
	int fd;

	if (argc < 2)
		return (EXIT_SUCCESS);


	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		fprintf(stderr, "%s: Error: '%s': No such file\n", PROGRAM_NAME, argv[1]);
		return (EXIT_FAILURE);
	}

	if (read(fd, magic_number, SELFMAG) != SELFMAG)
	{
		fprintf(stderr, "%s: Error: %s: Failed to read file's magic number\n", PROGRAM_NAME, argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

	if (memcmp(ELFMAG, magic_number, SELFMAG))
	{
		fprintf(stderr, "%s: Error: Not an ELF file - it has the wrong magic bytes at the start\n", PROGRAM_NAME);
		close(fd);
		return (EXIT_FAILURE);
	}

	if (!(elf = read_elf_header(fd)))
	{
		fprintf(stderr, "%s: Error: %s: Failed to read file header\n", PROGRAM_NAME, argv[1]);
		close(fd);
		return (EXIT_FAILURE);
	}

#if defined(TASK_0)
	print_ELF_header_info(elf);
#elif defined(TASK_1)
	print_elf_section_header_table(fd, elf);
#elif defined(TASK_2)
	print_elf_program_header_table(fd, elf);
#endif
	free_elf_info(elf);
	close(fd);
	return (EXIT_SUCCESS);
}

/**
 * read_elf_header - reads an ELF file and returns an Elf_header_info struct that
 *                   describes the ELF file (acquired by reading ELF header)
 * @fd: ELF file descriptor
 * Return: pointer to an Elf_hdr_info_t struct
 **/
static Elf_hdr_info_t *read_elf_header(int fd)
{
	unsigned char padding[PAD_SIZE];
	Elf_hdr_info_t *elf;

	if (
		!(elf = calloc(1, sizeof(Elf_hdr_info_t)))                                 ||
		!read_attr(fd, &elf->class,       sizeof(elf->class),       elf->encoding) ||
		!read_attr(fd, &elf->encoding,    sizeof(elf->encoding),    elf->encoding) ||
		!read_attr(fd, &elf->version1,    sizeof(elf->version1),    elf->encoding) ||
		!read_attr(fd, &elf->os_abi,      sizeof(elf->os_abi),      elf->encoding) ||
#ifdef TASK_0
		!(elf->os_abi_string  = get_ELF_os_abi_string(elf->os_abi))                ||
#endif
		!read_attr(fd, &elf->abi_version, sizeof(elf->abi_version), elf->encoding) ||
		!read_attr(fd, padding,           sizeof(padding),          elf->encoding) ||
		!read_attr(fd, &elf->type,        sizeof(elf->type),        elf->encoding) ||
#ifdef TASK_0
		!(elf->type_string    = get_ELF_type_string(elf->type))                    ||
#endif
		!read_attr(fd, &elf->machine,     sizeof(elf->machine),     elf->encoding) ||
#ifdef TASK_0
		!(elf->machine_string = get_ELF_machine_string(elf->machine))              ||
#endif
		!read_attr(fd, &elf->version2,    sizeof(elf->version2),    elf->encoding) ||
		!read_attr(fd, &elf->entry,       elf->class * 4,           elf->encoding) ||
		!read_attr(fd, &elf->phoff,       elf->class * 4,           elf->encoding) ||
		!read_attr(fd, &elf->shoff,       elf->class * 4,           elf->encoding) ||
		!read_attr(fd, &elf->flags,       sizeof(elf->flags),       elf->encoding) ||
		!read_attr(fd, &elf->ehsize,      sizeof(elf->ehsize),      elf->encoding) ||
		!read_attr(fd, &elf->phentsize,   sizeof(elf->phentsize),   elf->encoding) ||
		!read_attr(fd, &elf->phnum,       sizeof(elf->phnum),       elf->encoding) ||
		!read_attr(fd, &elf->shentsize,   sizeof(elf->shentsize),   elf->encoding) ||
		!read_attr(fd, &elf->shnum,       sizeof(elf->shnum),       elf->encoding) ||
		!read_attr(fd, &elf->shstrndx,    sizeof(elf->shstrndx),    elf->encoding)
	)
	{
		free_elf_info(elf);
		return (NULL);
	}

	return (elf);
}

/**
 * read_attr - reads an ELF file attribute from an ELF file
 * @fd: ELF file descriptor
 * @attr: pointer to attribute where value will be stored
 * @size: size of attribute
 * @encoding: encoding of attribute
 * Return: 1 on success | 0 on failure
 **/
int read_attr(int fd, void *attr, size_t size, uint8_t encoding)
{
	if (read(fd, attr, size) != (ssize_t)size)
		return (0);

	if (encoding == ELFDATA2MSB)
	{
		if (size == sizeof(uint16_t))
			*((uint16_t *)attr) = __bswap_16(*((uint16_t *)attr));
		else if (size == sizeof(uint32_t))
			*((uint32_t *)attr) = __bswap_32(*((uint32_t *)attr));
		else if (size == sizeof(uint64_t))
			*((uint64_t *)attr) = __bswap_64(*((uint64_t *)attr));
	}

	return (1);
}

/**
 * free_elf_info - frees all contents of an Elf_hdr_info_t struct
 * @elf: pointer to elf info struct
 **/
static void free_elf_info(Elf_hdr_info_t *elf)
{
	free(elf->os_abi_string);
	free(elf->type_string);
	free(elf->machine_string);
	free(elf);
}
