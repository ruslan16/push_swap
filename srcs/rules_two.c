/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:10:48 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:12:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_reverse_rotate_a(t_dupstruct *f, int button)
{
	int tmp;
	int len;

	if (f->len_stac_a != 0)
	{
		tmp = f->stac_a[f->len_stac_a - 1];
		len = f->len_stac_a - 1;
		while (len > 0)
		{
			f->stac_a[len] = f->stac_a[len - 1];
			len--;
		}
		f->stac_a[0] = tmp;
		if (button != 1)
			ft_printf("rra\n");
	}
	(f->v == 1) ? ft_print_stac(f, "rra", 'n') : ft_printf("");
}

void	ft_reverse_rotate_b(t_dupstruct *f, int button)
{
	int tmp;
	int len;

	if (f->len_stac_b != 0)
	{
		tmp = f->stac_b[f->len_stac_b - 1];
		len = f->len_stac_b - 1;
		while (len > 0)
		{
			f->stac_b[len] = f->stac_b[len - 1];
			len--;
		}
		f->stac_b[0] = tmp;
		if (button != 1)
			ft_printf("rrb\n");
	}
	(f->v == 1) ? ft_print_stac(f, "rrb", 'n') : ft_printf("");
}

void	ft_rotate_a(t_dupstruct *f, int button)
{
	int tmp;
	int i;
	int len;

	if (f->len_stac_a != 0)
	{
		i = 0;
		tmp = f->stac_a[0];
		len = f->len_stac_a - 1;
		while (i < len)
		{
			f->stac_a[i] = f->stac_a[i + 1];
			i++;
		}
		f->stac_a[len] = tmp;
		if (button != 1)
			ft_printf("ra\n");
	}
	(f->v == 1) ? ft_print_stac(f, "ra", 'n') : ft_printf("");
}

void	ft_rotate_b(t_dupstruct *f, int button)
{
	int tmp;
	int i;
	int len;

	if (f->len_stac_b != 0)
	{
		i = 0;
		tmp = f->stac_b[0];
		len = f->len_stac_b - 1;
		while (i < len)
		{
			f->stac_b[i] = f->stac_b[i + 1];
			i++;
		}
		f->stac_b[len] = tmp;
		if (button != 1)
			ft_printf("rb\n");
	}
	(f->v == 1) ? ft_print_stac(f, "rb", 'n') : ft_printf("");
}
