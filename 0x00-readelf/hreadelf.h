#ifndef HREADELF_H
#define HREADELF_H

#include <byteswap.h>
#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROGRAM_NAME "readelf"
#define CURRENT_VERSION 1
#define PH_SUMMARY "There are %d program headers, starting at offset %d\n\n"
#define PH_INTRO "Program Headers:"
#define PH_FIRST_ROW \
"  Type           Offset   VirtAddr           PhysAddr           FileSiz  MemSiz   Flg Align"
#define PH_FIRST_ROW32 \
"  Type           Offset   VirtAddr   PhysAddr   FileSiz MemSiz  Flg Align"
#define IS_INTERP_ROW 1

#define is_printable(x) ((x) >= 32 && (x) <= 126)
#define PAD_SIZE (EI_NIDENT - EI_PAD)

/**
 * struct Elf_hdr_info_st - a struct detailing info provided by an ELF header
 * @class: ELF file class. Either ELFCLASS32 or ELFCLASS64
 * @encoding: ELF file encoding. Either ELFDATA2MSB or ELFDATA2LSB
 * @version1: version. should always be 1
 * @os_abi: OS Application Binary Interface value
 * @os_abi_string: OS Application Binary Interface as a string
 * @abi_version: abi version
 * @type: ELF type (ET_*)
 * @type_string: string representation of ELF type
 * @machine: ELF machine type (EM_*)
 * @machine_string: string representation of ELF machine type
 * @version2: 2nd time version is mentioned in ELF file.
 * @entry: entry point address for ELF file code execution
 * @phoff: program header offset (bytes into file)
 * @shoff: section header offset (bytes into file)
 * @flags: processor-specific flags (EF_*). Should be 0.
 * @ehsize: size of ELF header
 * @phentsize: size of a program header
 * @phnum: number of program headers
 * @shentsize: size of a section header
 * @shnum: number of section headers
 * @shstrndx: index of string table section header
 **/
typedef struct Elf_hdr_info_st
{
	uint8_t  class;
	uint8_t  encoding;
	uint8_t  version1;
	uint8_t  os_abi;
	char    *os_abi_string;
	uint8_t  abi_version;
	uint16_t type;
	char    *type_string;
	uint16_t machine;
	char    *machine_string;
	uint32_t version2;
	uint64_t entry;
	uint64_t phoff;
	uint64_t shoff;
	uint32_t flags;
	uint16_t ehsize;
	uint16_t phentsize;
	uint16_t phnum;
	uint16_t shentsize;
	uint16_t shnum;
	uint16_t shstrndx;
} Elf_hdr_info_t;

/**
 * struct macro_matcher_s - matches a macro with a string description
 * @macro: macro
 * @macro_string: macro string
 **/
typedef struct macro_matcher_s
{
	uint32_t macro;
	char *macro_string;
} macro_matcher_t;


/* print_ELF_header.c prototypes */
void print_ELF_header_info(Elf_hdr_info_t *elf);
char *get_ELF_os_abi_string(uint8_t os_abi);
char *get_ELF_type_string(uint16_t type);
char *get_ELF_machine_string(uint16_t machine);


/* print_ELF_section_header_table.c prototypes */
void print_elf_section_header_table(int fd, Elf_hdr_info_t *elf);
Elf64_Shdr *read_section_header(int fd, int class, int encoding);
void print_sh_flags(uint32_t sh_flags);
void print_sh_type(uint32_t sh_type);

/* helper prototypes */
char *get_string_table(int fd, Elf_hdr_info_t *elf);
int read_attr(int fd, void *attr, size_t size, uint8_t encoding);



/* print_ELF_program_header_table.c prototypes */
int print_elf64_program_header_table(int ELF_fd);
int print_elf32_program_header_table(int ELF_fd);
int print_ELF64_program_header_row(Elf64_Phdr ph);
int print_ELF32_program_header_row(Elf32_Phdr ph);
void print_segment64(int ELF_fd, Elf64_Addr paddr, uint64_t filesz, char *st);
void print_segment32(int ELF_fd, Elf32_Addr paddr, uint32_t filesz, char *st);
int print_p_type(uint32_t p_type);
void print_p_flags(uint32_t p_flags);

/* to be removed later */
void read_elf32_header_MSB(Elf32_Ehdr *h, int fd);
void read_elf64_header_MSB(Elf64_Ehdr *h, int fd);
void read_elf64_section_MSB(Elf64_Shdr *h, int fd);
void read_elf32_section_MSB(Elf32_Shdr *h, int fd);
void read_elf64_program_MSB(Elf64_Phdr *h, int fd);
void read_elf32_program_MSB(Elf32_Phdr *h, int fd);
void print_elf_file_type(uint16_t e_type);

#endif /* HREADELF_H */
