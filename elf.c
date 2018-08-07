#include "woody_woodpacker.h"
#include "libft/libft.h"

/*
** Mmaps files, checks ELF headers for arch64, checks ET_EXEC, fetches .text sections
*/
int		check_elf64(t_file *host, const char *hname, t_file *virus, const char *vname)
{
	if (!hname || !vname)
	{
		printf("Error: Invalid target(s)\n");
		return (-1);
	}

	// Mmap files
	if (mmap_file(hname, host) == -1 || mmap_file(vname, virus) == -1)
		return (-1);

	// Check ELF64 headers
	if (check_elf64_header((Elf64_Ehdr *)(host->map)) == -1 || check_elf64_header((Elf64_Ehdr *)(virus->map)) == -1)
		return (-1);

	// Check ELF type
	if (((Elf64_Ehdr *)(host->map))->e_type != ET_EXEC)
	{
		printf("Error: Invalid ELF file type: Only executables supported\n");
		return (-1);
	}

	// Find .text section
	if (find_elf64_section(host, ".text") == -1 || find_elf64_section(virus, ".text") == -1)
		return (-1);

	return (0);
}

/*
** Check ELF header compatibility with ELF64
*/
int		check_elf64_header(Elf64_Ehdr *ehdr)
{
	if (ehdr->e_ident[EI_MAG0] != ELFMAG0 || \
			ehdr->e_ident[EI_MAG1] != ELFMAG1 || \
			ehdr->e_ident[EI_MAG2] != ELFMAG2 || \
			ehdr->e_ident[EI_MAG3] != ELFMAG3 || \
			ehdr->e_ident[EI_CLASS] != ELFCLASS64)
	{
		printf("Error: Invalid ELF header: Only ELF 64bit supported\n");
		return (-1);
	}
	return (0);
}

/*
** Fetches .text section
*/
int		find_elf64_section(t_file *file, const char *sect)
{
	Elf64_Ehdr		*ehdr;
	Elf64_Shdr		*shdr;
	Elf64_Shdr		stable;
	char			*sname;
	int				shnum;

	ehdr = (Elf64_Ehdr *)(file->map);
	shdr = (Elf64_Shdr *)(file->map + ehdr->e_shoff);
	stable = shdr[ehdr->e_shstrndx];
	sname = (char *)(file->map + stable.sh_offset);

	if ((Elf64_Off)file->size < ehdr->e_shoff + ehdr->e_shnum * ehdr->e_shentsize)
	{
		printf("Error: Section headers table extends beyond file limits\n");
		return (-1);
	}

	for (shnum = 0 ; shnum < ehdr->e_shnum ; shnum++)
	{
		stable = shdr[shnum];
		if ((Elf64_Off)file->size < shdr[shnum].sh_offset)
		{
			printf("Error: Section %d extends beyond file limits\n", shnum);
			return (-1);
		}
		else if (!ft_strcmp(sname + stable.sh_name, sect))
		{
			file->sh_offset = stable.sh_offset;
			file->sh_size = stable.sh_size;
			return (0);
		}
	}
	
	printf("Error: Unable to find .text section\n");
	return (-1);
}

/*
** Updates segments offset and size
*/
void	update_elf64_segments(Elf64_Ehdr *ehdr, Elf64_Phdr *phdr, uint64_t v_size, Elf64_Addr *v_off, Elf64_Addr *b_addr, Elf64_Addr *o_ent)
{
	uint16_t		phnum;
	int				found;

	found = 0;
	for (phnum = 0 ; phnum < ehdr->e_phnum ; phnum++, phdr++)
	{
		if (found && phdr->p_offset >= *v_off)
		{
			phdr->p_offset += PAGE_SIZE;
		}
		else if (phdr->p_type == PT_LOAD && phdr->p_flags & PF_X)
		{
			*v_off = phdr->p_offset + phdr->p_filesz;
			*b_addr = phdr->p_vaddr;
			*o_ent = ehdr->e_entry;
			found++;

			ehdr->e_entry = phdr->p_vaddr + phdr->p_filesz + 256;
			phdr->p_filesz += v_size + 256;
			phdr->p_memsz += v_size + 256;
		}
	}
}

/*
** Updates sections offset and size
*/
void	update_elf64_sections(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, Elf64_Off v_off, uint64_t v_size)
{
	uint16_t		shnum;

	for (shnum = 0 ; shnum < ehdr->e_shnum ; shnum++, shdr++)
	{
		if (shdr->sh_offset + shdr->sh_size == v_off)
			shdr->sh_size += v_size + 256;
		if (shdr->sh_offset >= v_off)
			shdr->sh_offset += PAGE_SIZE;
	}
}
