// compile: gcc head_reader.c -o head_reader
// run: head_reader inputfile

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

#define EI_NIDENT (16)

#define ET_NONE (0)
#define ET_REL (1)
#define ET_EXEC (2)
#define ET_DYN (3)
#define ET_CORE (4)
#define ET_NUM (5)
#define ET_LOPROC (0xff00)
#define ET_HIPROC (0xffff)

typedef struct
{
	uint8_t chare_ident[EI_NIDENT];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uint64_t e_entry;
	uint64_t e_phoff;
	uint64_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} Elf64_Ehdr;

void parse_and_print(Elf64_Ehdr* hdr)
{
	printf("ELF Header:\n");

	// the Elf header is now in hdr, please parse it
	// for example, the magic
	printf("  Magic:\t");
	for (int i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", hdr->chare_ident[i]);
	}
	printf("\n");

	// follow the example you can parse the remain header
	/* --------- FILL your code here  --------- */
	printf("  Class:\t\t\t\t");
	if(hdr->chare_ident[4] == 2) printf("ELF64");
	else if(hdr->chare_ident[4] == 0) printf("ELFNONE"); // illegal class
	else if(hdr->chare_ident[4] == 1) printf("ELE32");
	printf("\n");
	
	printf("  Data:\t");
	printf("\t\t\t\t2's complement, %s", hdr->chare_ident[5]?"little endian":"big endian");
	printf("\n");

	printf("  Version:\t");
	// printf("%d//", hdr->e_version);
	printf("\t\t\t%d (current)", /**hdr->chare_ident[6]**/ hdr->e_version);
	printf("\n");

	printf("  OS/ABI:\t");
	printf("\t\t\tUNIX - System V");
	printf("\n");

	printf("  ABI Version:\t");
	printf("\t\t\t0");
	printf("\n");
	
	printf("  Type:\t\t\t\t\t");
	if(hdr->e_type == ET_NONE) printf("NONE (No file type)");
	else if(hdr->e_type == ET_REL) printf("REL (Relocatable file)");
	else if(hdr->e_type == ET_EXEC) printf("EXEC (Executable file)");
	else if(hdr->e_type == ET_DYN) printf("DYN (Shared object file)");
	else if(hdr->e_type == ET_CORE) printf("CORE (Core file)");
	// printf("\t\t\t\t%d", hdr->e_type);
	printf("\n");

	printf("  Machine:\t");
	if(hdr->e_machine == 62) printf("\t\t\tAdvanced Micro Devices X86-64");
	else printf("\t\t\t%d", hdr->e_machine /** Advanced Micro Devices X86-64 **/);
	printf("\n");

	printf("  Version:\t");
	printf("\t\t\t%#x", hdr->e_version);
	printf("\n");

	printf("  Entry point address:\t");
	printf("\t\t%#lx", hdr->e_entry);
	printf("\n");

	printf("  Start of program headers:\t");
	printf("\t%ld (bytes into file)", hdr->e_phoff);
	printf("\n");

	printf("  Start of section headers:\t");
	printf("\t%ld (bytes into file)", hdr->e_shoff);
	printf("\n");

	printf("  Flags:\t");
	printf("\t\t\t0x%x", hdr->e_flags);
	printf("\n");

	printf("  Size of this header:\t");
	printf("\t\t%d (bytes)", hdr->e_ehsize);
	printf("\n");

	printf("  Size of program headers:\t");
	printf("\t%d (bytes)", hdr->e_phentsize);
	printf("\n");

	printf("  Number of program headers:\t");
	printf("\t%d", hdr->e_phnum);
	printf("\n");

	printf("  Size of section headers:\t");
	printf("\t%d (bytes)", hdr->e_shentsize);
	printf("\n");

	printf("  Number of section headers:\t");
	printf("\t%d", hdr->e_shnum);
	printf("\n");

	printf("  Section header string table index:\t");
	printf("%d", hdr->e_shstrndx);
	printf("\n");
}

// if you don't understand argc and argv,
// refer to https://baike.baidu.com/item/argc%20argv/10826112
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("please provide ELF file path");
		exit(1);
	}

	char *filepath = argv[1];
	FILE *fptr = fopen(filepath, "r"); // read-only mode open file

	if (!fptr)
	{
		printf("please provide valid ELF file path");
		exit(1);
	}

	Elf64_Ehdr* header = malloc(sizeof(Elf64_Ehdr));

	fread(header, sizeof(Elf64_Ehdr), 1, fptr);

	parse_and_print(header);

	free(header);

	fclose(fptr);

	return 0;
}

