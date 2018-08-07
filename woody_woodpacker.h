#ifndef WOODY_WOODPACKER_H
# define WOODY_WOODPACKER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define PAGE_SIZE	4096

typedef struct		s_file
{
	int				fd;
	void			*map;
	off_t			size;
	Elf64_Off		sh_offset;
	uint64_t		sh_size;
}					t_file;

void				*get_random_key(size_t size);
void				swap(int *a, int *b);
unsigned char		*encrypt_zone(char *zone, size_t size);
int					patch_addr(void *m, size_t len, uint64_t pat, uint64_t val);
off_t				size_file(int fd);
void				munmap_file(t_file *file);
int					mmap_file(const char *name, t_file *file);
int					check_elf64(t_file *host, const char *hname, t_file *virus, const char *vname);
int					check_elf64_header(Elf64_Ehdr *ehdr);
int					find_elf64_section(t_file *file, const char *sect);
void				update_elf64_segments(Elf64_Ehdr *ehdr, Elf64_Phdr *phdr, uint64_t v_size, Elf64_Addr *v_off, Elf64_Addr *b_addr, Elf64_Addr *o_ent);
void				update_elf64_sections(Elf64_Ehdr *ehdr, Elf64_Shdr *shdr, Elf64_Off v_off, uint64_t v_size);

#endif
