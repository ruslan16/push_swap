/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:11:57 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:12:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_sort_four(t_dupstruct *f)
{
	ft_push_b(f, 0);
	ft_sort_three(f->stac_a, f, 'a');
	ft_push_a(f, 0);
	if (f->stac_a[0] == ft_highelement(f->stac_a, f->len_stac_a))
		ft_rotate_a(f, 0);
	else if (f->stac_a[0] > f->stac_a[1])
	{
		ft_swapab(f, 'a', 0);
		ft_push_b(f, 0);
		if (f->stac_a[0] > f->stac_a[1])
			ft_swapab(f, 'a', 0);
		ft_push_a(f, 0);
	}
}

void	ft_sort_five_d(t_dupstruct *f)
{
	if ((f->stac_a[0] > f->stac_a[1]) && (f->stac_b[0] < f->stac_b[1]))
		ft_ss(f, 0);
	else if (f->stac_a[0] > f->stac_a[1])
		ft_swapab(f, 'a', 0);
	else if ((f->len_stac_b == 2) && (f->stac_b[0] < f->stac_b[1]))
		ft_swapab(f, 'b', 0);
	ft_push_a(f, 0);
	if (f->stac_a[0] == ft_highelement(f->stac_a, 4))
		ft_rotate_a(f, 0);
	if (f->stac_a[0] > f->stac_a[1])
		ft_swapab(f, 'a', 0);
	ft_push_a(f, 0);
	if (f->stac_a[0] == ft_highelement(f->stac_a, 4))
		ft_rotate_a(f, 0);
}

void	ft_sort_five(t_dupstruct *f)
{
	ft_push_b(f, 0);
	ft_push_b(f, 0);
	ft_sort_three(f->stac_a, f, 'a');
	if ((f->stac_b[0] < f->stac_b[1]) && (f->stac_a[2] > f->stac_b[0]))
		ft_swapab(f, 'b', 0);
	else if ((f->stac_b[0] > f->stac_b[1]) && (f->stac_a[2] < f->stac_b[1]))
		ft_swapab(f, 'b', 0);
	ft_push_a(f, 0);
	if (f->stac_a[0] == ft_highelement(f->stac_a, 4))
		ft_rotate_a(f, 0);
	if (f->stac_a[0] > f->stac_a[1])
	{
		ft_swapab(f, 'a', 0);
		ft_push_b(f, 0);
	}
	ft_sort_five_d(f);
}
