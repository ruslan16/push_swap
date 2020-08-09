/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:09:19 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:09:19 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_clear_highwin(char *cmd, char stac)
{
	ft_putstr("\x1b[2J");
	if (stac == 'a')
		ft_printf("sa\n\n");
	else if (stac == 'b')
		ft_printf("sb\n\n");
	else
		ft_printf("%s\n\n", cmd);
	ft_printf("STAC_A :\n");
}

void	color_high_stac(t_dupstruct *f, char *cmd, char stac, int i)
{
	int j;

	j = 0;
	ft_putstr("\x1b[2J");
	if (stac == 'a')
		ft_printf("\033[1;33msa\033[0m\n\n");
	else if (stac == 'b')
		ft_printf("\033[1;33sb\033[0m\n\n");
	else
		ft_printf("\033[1;33m%s\033[0m\n\n", cmd);
	ft_printf("\033[1;35mSTAC_A :\033[0m\n");
	while (i < f->len_stac_a)
	{
		ft_printf("\033[1;36m%d\033[0m ", f->stac_a[i]);
		i++;
	}
	ft_printf("\n\033[1;35mSTAC_B :\033[0m\n");
	while (j < f->len_stac_b)
	{
		ft_printf("\033[1;36m%d\033[0m ", f->stac_b[j]);
		j++;
	}
	ft_printf("\n");
	usleep(200 * 1000);
}

void	write_highstac(t_dupstruct *f, char *cmd, char stac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (f->c == 1)
	{
		color_high_stac(f, cmd, stac, 0);
		return ;
	}
	ft_clear_highwin(cmd, stac);
	while (i < f->len_stac_a)
	{
		ft_printf("%d ", f->stac_a[i]);
		i++;
	}
	ft_printf("\nSTAC_B :\n");
	while (j < f->len_stac_b)
	{
		ft_printf("%d ", f->stac_b[j]);
		j++;
	}
	ft_printf("\n");
	usleep(200 * 1000);
}
