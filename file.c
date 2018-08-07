#include "woody_woodpacker.h"

off_t		size_file(int fd)
{
	off_t	off;

	if (fd < 0)
	{
		printf("Error: Unable to get file size: Invalid file descriptor\n");
		return (0);
	}
	lseek(fd, 0, SEEK_SET);
	off = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	return (off);
}

void	munmap_file(t_file *file)
{
	if (file->fd > 0)
	{
		munmap(file->map, file->size);
		close(file->fd);
	}
}

int		mmap_file(const char *name, t_file *file)
{
	file->fd = open(name, O_RDONLY);
	if (file->fd < 0)
	{
		printf("Error: Unable to open file\n");
		return (-1);
	}
	if ((file->size = size_file(file->fd)) <= 0)
	{
		printf("Error: Invalid file size\n");
		close(file->fd);
		return (-1);
	}
	if ((file->map = mmap(NULL, file->size, PROT_READ|PROT_WRITE, MAP_PRIVATE, file->fd, 0)) == MAP_FAILED)
	{
		printf("Error: Unable to mmap file descriptor\n");
		close(file->fd);
		return (-1);
	}
	return (0);
}
