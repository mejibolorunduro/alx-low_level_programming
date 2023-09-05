#include "main.h"

/**
 * error_exit - to print an error message and exit with the specified code.
 * @exit_code: exit code.
 * @message: error message displayed
 */
void error_exit(int exit_code, const char *message)
{
    fprintf(stderr, "%s", message);
    exit(exit_code);
}

/**
 * print_elf_header - Print the information from the header.
 * @header: Pointer
 */
void print_elf_header(Elf64_Ehdr *header)
{
    printf("Magic:   ");
    for (int q = 0; q < EI_NIDENT; q++)
    {
        printf("%02x", header->e_ident[q]);
        if (q < EI_NIDENT - 1)
	{
            printf(" ");
        }
    }
    printf("\n");

    printf("Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("Type:                              %s\n", header->e_type == ET_EXEC ? "EXEC (Executable file)" : (header->e_type == ET_DYN ? "DYN (Shared object file)" : "OTHER"));
    printf("Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
       exit(98, "Usage: %s elf_filename\n", argv[0]);
    }

    int f_des = open(argv[1], O_RDONLY);
    if (f_des == -1)
    {
       exit(98, "Error: Cannot open file '%s'\n", argv[1]);
    }

    Elf64_Ehdr header;
    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read != sizeof(Elf64_Ehdr) || header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
        header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
    {
       exit(98, "Error: '%s' is not an ELF file\n", argv[1]);
    }

    print_elf_header(&header);

    close(f_des);
    return 0;
}
