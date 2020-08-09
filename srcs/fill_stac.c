/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:10:14 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:12:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_fill_stac_f(t_dupstruct *f, int i, int j, int count_stac)
{
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_ten[j] = f->sorted_stac[i - 8];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a - (f->len_stac_a / count_stac) * 10))
	{
		f->stac_eleven[j] = f->sorted_stac[i - 9];
		i++;
	}
}

void	ft_fill_stac_t(t_dupstruct *f, int i, int j, int count_stac)
{
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_seven[j] = f->sorted_stac[i - 5];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_eight[j] = f->sorted_stac[i - 6];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_nine[j] = f->sorted_stac[i - 7];
		i++;
	}
	j = -1;
	ft_fill_stac_f(f, i, j, count_stac);
}

void	ft_fill_stac_d(t_dupstruct *f, int i, int j, int count_stac)
{
	if (f->len_stac_a <= 100)
	{
		while (j++ < (f->len_stac_a - (f->len_stac_a / 5) * 4))
		{
			f->stac_five[j] = f->sorted_stac[i - 3];
			i++;
		}
		return ;
	}
	else
	{
		while (j++ < (f->len_stac_a / count_stac))
		{
			f->stac_five[j] = f->sorted_stac[i - 3];
			i++;
		}
	}
	j = -1;
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_six[j] = f->sorted_stac[i - 4];
		i++;
	}
	ft_fill_stac_t(f, i, -1, count_stac);
}

void	ft_fill_stac(t_dupstruct *f, int i, int j, int count_stac)
{
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_two[j] = f->sorted_stac[i];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_three[j] = f->sorted_stac[i - 1];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / count_stac))
	{
		f->stac_four[j] = f->sorted_stac[i - 2];
		i++;
	}
	j = -1;
	ft_fill_stac_d(f, i, j, count_stac);
}
