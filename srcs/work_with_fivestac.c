/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_fivestac.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:12:24 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:51:19 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	work_with_five(t_dupstruct *f, int count_stacs, int j, int size_stacs)
{
	int count;
	int i;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_five, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_five, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	if (count_stacs > 5)
		work_with_sixstac(f, 0, 0, size_stacs);
}

void	work_with_four(t_dupstruct *f, int count_stacs, int j, int size_stacs)
{
	int count;
	int i;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_four, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_four, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	(count_stacs == 5) ? work_with_five(f, count_stacs, 0, f->len_stac_a)
	: work_with_five(f, count_stacs, 0, size_stacs);
}

void	work_with_three(t_dupstruct *f, int count_stacs, int j, int size_stacs)
{
	int count;
	int i;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_three, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_three, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_four(f, count_stacs, 0, size_stacs);
}

void	work_with_two(t_dupstruct *f, int count_stacs, int j, int size_stacs)
{
	int count;
	int i;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_two, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_two, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_three(f, count_stacs, 0, size_stacs);
}

void	work_with_one(t_dupstruct *f, int count_stacs, int j, int size_stacs)
{
	int count;
	int i;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_one, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_one, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_two(f, count_stacs, 0, size_stacs);
}
