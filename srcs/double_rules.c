/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:10:08 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:10:52 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_ss(t_dupstruct *f, int button)
{
	ft_swapab(f, 'a', 1);
	ft_swapab(f, 'b', 1);
	if (button == 0)
		ft_printf("ss\n");
}

void	ft_rotate_ab(t_dupstruct *f, int button)
{
	ft_rotate_a(f, 1);
	ft_rotate_b(f, 1);
	if (button == 0)
		ft_printf("rr\n");
}

void	ft_reverse_rotate_ab(t_dupstruct *f, int button)
{
	ft_reverse_rotate_a(f, 1);
	ft_reverse_rotate_b(f, 1);
	if (button == 0)
		ft_printf("rrr\n");
}
