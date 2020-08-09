/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_elevenstac.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:12:14 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:12:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	work_with_tenstac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_ten, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_ten, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_elevenstac(f, 0, 0, f->len_stac_a);
}

void	work_with_ninestac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_nine, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_nine, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_tenstac(f, 0, 0, size_stacs);
}

void	work_with_eightstac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_eight, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_eight, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_ninestac(f, 0, 0, size_stacs);
}

void	work_with_sevenstac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_seven, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_seven, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_eightstac(f, 0, 0, size_stacs);
}

void	work_with_sixstac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_six, size_stacs))
				break ;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_six, size_stacs))
				break ;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_sevenstac(f, 0, 0, size_stacs);
}
