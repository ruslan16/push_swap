/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlc_fun_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:10:03 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:12:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

int		ft_size_stac(char *str[], int size)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	j = 0;
	while (i < size)
	{
		while (str[i][j] != '\0')
		{
			while (ft_isspace(str[i][j]))
				j++;
			if (ft_isspace(str[i][j + 1]) || str[i][j + 1] == '\0')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	ft_clear_stacs(t_dupstruct *f, int count_stacs)
{
	free(f->stac_one);
	free(f->stac_two);
	free(f->stac_three);
	free(f->stac_four);
	free(f->stac_five);
	if (count_stacs == 11)
	{
		free(f->stac_six);
		free(f->stac_seven);
		free(f->stac_eight);
		free(f->stac_nine);
		free(f->stac_ten);
		free(f->stac_eleven);
	}
	free(f->sorted_stac);
}

int		*ft_intdup(int *num, int *num1, int len)
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

int		ft_intchr(int num, int *stac, int len_stac)
{
	int i;

	i = 0;
	if (!stac)
		return (0);
	while (i < len_stac)
	{
		if (num == stac[i])
			return (1);
		i++;
	}
	return (0);
}

int		*ft_sorted(int *num, int len)
{
	int i;
	int *stac;
	int j;
	int *dupnum;

	i = 0;
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
