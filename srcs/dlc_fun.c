#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

int		ft_highelement(int *num, int len)
{
	int i;
	int max;

	i = 0;
	max = num[0];
	while (i < len)
	{
		if (num[i] > max)
			max = num[i];
		i++;
	}
	return (max);
}

int		ft_lowelement(int *num, int len)
{
	int i;
	int min;

	i = 0;
	min = num[0];
	while (i < len)
	{
		if (num[i] < min)
			min = num[i];
		i++;
	}
	return (min);
}

int 	ft_index_lowel(int *num, int len)
{
	int i;
	int min;
	int index;

	i = 0;
	min = num[0];
	index = 0;
	while (i < len)
	{
		if (num[i] < min)
		{
			min = num[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	ft_index_highel(int *num, int len)
{
	int i;
	int max;
	int index;

	i = 0;
	max = num[0];
	index = 0;
	while (i < len)
	{
		if (num[i] > max)
		{
			max = num[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int 	ft_is_sorted(int *num, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (num[i] > num[i + 1] && (i != len - 1))
			return (0);
		i++;
	}
	return (1);
}
