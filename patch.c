#include "woody_woodpacker.h"

int		patch_addr(void *m, size_t len, uint64_t pat, uint64_t val)
{
	unsigned char	*p;
	uint64_t		n;
	size_t			i;

	p = (unsigned char *)m;
	i = 0;
	while (i < (len - 7))
	{
		n = *((uint64_t *)(p + i));
		if (n == pat)
		{
			*((uint64_t *)(p + i)) = val;
		}
		i++;
	}
	return (0);
}
