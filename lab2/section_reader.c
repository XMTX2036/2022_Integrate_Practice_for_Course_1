// compile: gcc section_reader.c -o section_reader
// run: section_reader inputfile

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdint.h>

#define EI_NIDENT (16)

#define SHT_NULL          0             /* Section header table entry unused */
#define SHT_PROGBITS      1             /* Program data */
#define SHT_SYMTAB        2             /* Symbol table */
#define SHT_STRTAB        3             /* String table */
#define SHT_RELA          4             /* Relocation entries with addends */
#define SHT_HASH          5             /* Symbol hash table */
#define SHT_DYNAMIC       6             /* Dynamic linking information */
#define SHT_NOTE          7             /* Notes */
#define SHT_NOBITS        8             /* Program space with no data (bss) */
#define SHT_REL           9             /* Relocation entries, no addends */
#define SHT_SHLIB         10            /* Reserved */
#define SHT_DYNSYM        11            /* Dynamic linker symbol table */
#define SHT_INIT_ARRAY    14            /* Array of constructors */
#define SHT_FINI_ARRAY    15            /* Array of destructors */
#define SHT_PREINIT_ARRAY 16            /* Array of pre-constructors */
#define SHT_GROUP         17            /* Section group */
#define SHT_SYMTAB_SHNDX  18            /* Extended section indeces */
#define SHT_NUM           19            /* Number of defined types.  */
#define SHT_LOOS          0x60000000    /* Start OS-specific.  */
#define SHT_GNU_ATTRIBUTES 0x6ffffff5   /* Object attributes.  */
#define SHT_GNU_HASH      0x6ffffff6    /* GNU-style hash table.  */
#define SHT_GNU_LIBLIST   0x6ffffff7    /* Prelink library list */
#define SHT_CHECKSUM      0x6ffffff8    /* Checksum for DSO content.  */
#define SHT_LOSUNW        0x6ffffffa    /* Sun-specific low bound.  */
#define SHT_SUNW_move     0x6ffffffa
#define SHT_SUNW_COMDAT   0x6ffffffb
#define SHT_SUNW_syminfo  0x6ffffffc
#define SHT_GNU_verdef    0x6ffffffd    /* Version definition section.  */
#define SHT_GNU_verneed   0x6ffffffe    /* Version needs section.  */
#define SHT_GNU_versym    0x6fffffff    /* Version symbol table.  */
#define SHT_HISUNW        0x6fffffff    /* Sun-specific high bound.  */
#define SHT_HIOS          0x6fffffff    /* End OS-specific type */
#define SHT_LOPROC        0x70000000    /* Start of processor-specific */
#define SHT_HIPROC        0x7fffffff    /* End of processor-specific */
#define SHT_LOUSER        0x80000000    /* Start of application-specific */
#define SHT_HIUSER        0x8fffffff    /* End of application-specific */

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

typedef struct
{
	uint32_t sh_name;
	uint32_t sh_type;
	uint64_t sh_flags;
	uint64_t sh_addr;
	uint64_t sh_offset;
	uint64_t sh_size;
	uint32_t sh_link;
	uint32_t sh_info;
	uint64_t sh_addralign;
	uint64_t sh_entsize;
} Elf64_Shdr;

void parse_section_header(Elf64_Shdr *shdr, int index)
{
	// the section header array is now in shdr, please parse it
	printf("[%2d]", index);
	// printf("section - %d\n", index);
	// CAUTIONS: name is very difficult, so you can ignore name field
	// or you can try to parse it
	printf(" %016x", shdr->sh_name);
	// printf("Name (index in string table): 0x%x\n", shdr->sh_name);
	if(shdr->sh_type == SHT_NULL) printf(" %16s", "NULL");
	else if(shdr->sh_type == SHT_PROGBITS) printf(" %16s", "PROGBITS");
	else if(shdr->sh_type == SHT_SYMTAB) printf(" %16s", "SYMTAB");
	else if(shdr->sh_type == SHT_STRTAB) printf(" %16s", "STRTAB");
	else if(shdr->sh_type == SHT_RELA) printf(" %16s", "RELA");
	else if(shdr->sh_type == SHT_HASH) printf(" %16s", "HASH");
	else if(shdr->sh_type == SHT_DYNAMIC) printf(" %16s", "DYNAMIC");
	else if(shdr->sh_type == SHT_NOTE) printf(" %16s", "NOTE");
	else if(shdr->sh_type == SHT_NOBITS) printf(" %16s", "NOBITS");
	else if(shdr->sh_type == SHT_REL) printf(" %16s", "REL");
	else if(shdr->sh_type == SHT_SHLIB) printf(" %16s", "SHLIB");
	else if(shdr->sh_type == SHT_DYNSYM) printf(" %16s", "DYNSYM");
	else if(shdr->sh_type == SHT_INIT_ARRAY) printf(" %16s", "INIT_ARRAY");
	else if(shdr->sh_type == SHT_FINI_ARRAY) printf(" %16s", "FINI_ARRAY");
	else if(shdr->sh_type == SHT_PREINIT_ARRAY) printf(" %16s", "PREINIT_ARRAY");
	else if(shdr->sh_type == SHT_GROUP) printf(" %16s", "GROUP");
	else if(shdr->sh_type == SHT_SYMTAB_SHNDX) printf(" %16s", "SYMTAB_SHNDX");
	else if(shdr->sh_type == SHT_NUM) printf(" %16s", "NUM");
	else printf(" %016x", shdr->sh_type);
	// printf("Type: 0x%x\n", shdr->sh_type);
	printf(" %016lx", shdr->sh_addr);
	// printf("Address: 0x%lx\n", shdr->sh_addr);
	/* --------- FILL your code here  --------- */
	printf("         %08lx", shdr->sh_offset);
	// printf("Offset: %08lx\n", shdr->sh_offset);

	// printf("Size: %016lx\n", shdr->sh_size);
	// printf("EntSize: %016lx\n", shdr->sh_entsize);
	// printf("Flags: %lx\n", shdr->sh_flags);
	// printf("Link: %d\n", shdr->sh_link);
	// printf("Info: %d\n", shdr->sh_info);
	// printf("Align: %ld\n", shdr->sh_addralign);
	printf("\n");
	printf("     %016lx", shdr->sh_size);
	printf(" %016lx", shdr->sh_entsize);
	printf(" %8lx", shdr->sh_flags);
	printf(" %8d", shdr->sh_link);
	printf(" %8d", shdr->sh_info);
	printf(" %8ld", shdr->sh_addralign);
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

	Elf64_Ehdr *header = malloc(sizeof(Elf64_Ehdr));

	fread(header, sizeof(Elf64_Ehdr), 1, fptr);

	// get section header table file offset
	uint64_t section_hdr_offset = header->e_shoff;
	uint32_t section_hdr_conut = header->e_shnum;

	printf("There are %d section headers, starting at offset 0x%lx:\n", section_hdr_conut, section_hdr_offset);

	free(header);

	// switch offset
	fseek(fptr, section_hdr_offset, SEEK_SET);

	Elf64_Shdr *array = malloc(section_hdr_conut * sizeof(Elf64_Shdr));
	// read all section header
	fread(array, section_hdr_conut * sizeof(Elf64_Shdr), 1, fptr);

	printf("Section Headers:\n");
	printf("[Nr] %16s %16s %16s %16s\n", "Name", "Type", "Address", "Offset");
	printf("     %16s %16s %8s %8s %8s %8s\n", "Size", "EntSize", "Flags", "Link", "Info", "Align");
	for (int i = 0; i < section_hdr_conut; i++)
	{
		parse_section_header(&array[i], i);
	}

	free(array);

	fclose(fptr);

	return 0;
}
