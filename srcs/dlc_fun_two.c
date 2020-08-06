#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

int 	*ft_intdup(int *num, int *num1, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		num[i] = num1[i];
		i++;
	}
	return (num);
}

int 	ft_intchr(int num, int *stac, int len_stac)
{
	int i;

	i = 0;
	while (i < len_stac)
	{
		if (num == stac[i])
			return (1);
		i++;
	}
	return (0);
}

int 	*ft_sorted(int *num, int len)
{
	int i;
	int *stac;
	int j;
	int *dupnum;

	i = 0;
	j = 0;
	stac = ft_memalloc(len);
	dupnum = ft_memalloc(len);
	dupnum = ft_intdup(dupnum, num, len);
	while (i < len)
	{
		stac[i] = ft_lowelement(dupnum, len - i);
		j = ft_index_lowel(dupnum, len - i);
		dupnum[j] = dupnum[len - i - 1];
		i++;
	}
	free(dupnum);
	return (stac);
}