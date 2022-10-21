#include <hreadelf.h>

/**
 * get_string_table - returns alloc'd buffer of an ELF string table
 * @fd: ELF file descriptor
 * @elf: pointer to Elf_Hdr_info_t struct (used to find string table)
 * Return: pointer to alloc'd buffer contiaining string table contents
 **/
char *get_string_table(int fd, Elf_hdr_info_t *elf)
{
	uint64_t offset = elf->shoff + (elf->shentsize * elf->shstrndx);
	char *string_table;
	Elf64_Shdr *sh;

	lseek(fd, offset, SEEK_SET);
	sh = read_section_header(fd, elf->class, elf->encoding);
	string_table = malloc(sizeof(char) * sh->sh_size);
	lseek(fd, sh->sh_offset, SEEK_SET);
	read(fd, string_table, sh->sh_size);
	lseek(fd, 0, SEEK_SET);
	free(sh);
	return (string_table);
}
