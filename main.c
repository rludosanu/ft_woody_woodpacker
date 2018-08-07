#include "woody_woodpacker.h"

int		main(int ac, char **av)
{
	t_file			host;
	t_file			virus;
	int				woodyfd;
	Elf64_Ehdr		*ehdr;
	Elf64_Phdr		*phdr;
	Elf64_Shdr		*shdr;
	Elf64_Addr		virus_offset;
	Elf64_Addr		base_address;
	Elf64_Addr		old_entry;
	int				pad;
	Elf64_Off		i;
	unsigned char	*key;
	uint64_t		tmp_p;
	uint64_t		tmp_l;

	// Check arguments
	if (ac != 2)
	{
		printf("Usage: ./%s <host>\n", av[0]);
		return (-1);
	}

	// Check and mmap elf
	if (check_elf64(&host, av[1], &virus, "./depacker") == -1)
	{	
		munmap_file(&host);
		munmap_file(&virus);
		return (-1);
	}

	// Init headers
	ehdr = (Elf64_Ehdr *)(host.map);
	phdr = (Elf64_Phdr *)(host.map + ehdr->e_phoff);
	shdr = (Elf64_Shdr *)(host.map + ehdr->e_shoff);
	
	// Init re-usable
	virus_offset = 0;
	base_address = 0;
	old_entry = 0;
	
	// Init temporary
	i = 0;
	pad = 0;

	// Update segment headers
	update_elf64_segments(ehdr, phdr, virus.sh_size, &virus_offset, &base_address, &old_entry);

	// Update section headers
	update_elf64_sections(ehdr, shdr, virus_offset, virus.sh_size);

	// Update section header table offset
	ehdr->e_shoff += PAGE_SIZE;

	// Encrypt .text section
	key = encrypt_zone((char *)(host.map + host.sh_offset), host.sh_size);

	// Patch addresses
	tmp_p = base_address + host.sh_offset;
	tmp_l = host.sh_offset + host.sh_size;
	patch_addr(virus.map + virus.sh_offset, virus.sh_size, 0x1111111111111111, (uint64_t)(base_address + host.sh_offset));
	patch_addr(virus.map + virus.sh_offset, virus.sh_size, 0x2222222222222222, (uint64_t)(host.sh_size));
	patch_addr(virus.map + virus.sh_offset, virus.sh_size, 0x3333333333333333, (uint64_t)(ehdr->e_entry - 256));
	patch_addr(virus.map + virus.sh_offset, virus.sh_size, 0x4444444444444444, (uint64_t)(old_entry));
	patch_addr(virus.map + virus.sh_offset, virus.sh_size, 0x5555555555555555, tmp_p - (tmp_p % 4096));
	patch_addr(virus.map + virus.sh_offset, virus.sh_size, 0x6666666666666666, tmp_l);

	// Open destination file
	if ((woodyfd = open("woody", O_TRUNC|O_CREAT|O_WRONLY, S_IRUSR|S_IXUSR|S_IWUSR)) < 0)
	{
		printf("Error: Unable to create woody\n");
		munmap_file(&host);
		munmap_file(&virus);
		return (-1);
	}

	// Write destination file
	write(woodyfd, host.map, virus_offset);
	write(woodyfd, key, 256);
	write(woodyfd, virus.map + virus.sh_offset, virus.sh_size);
	for (i = 0 ; i < PAGE_SIZE - virus.sh_size - 256 ; i++)
		write(woodyfd, &pad, 1);
	write(woodyfd, host.map + virus_offset, host.size - virus_offset);

	// Close files
	close(woodyfd);
	munmap_file(&host);
	munmap_file(&virus);
	free(key);
	return (0);
}
