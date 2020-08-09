/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:09:09 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 21:02:22 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_clear_win(char *cmd, char stac)
{
	ft_putstr("\x1b[2J");
	if (stac == 'a')
		ft_printf("sa\n");
	else if (stac == 'b')
		ft_printf("sb\n");
	else
		ft_printf("%s\n", cmd);
	ft_printf("STAC_A	STAC_B\n");
}

void	ft_print_color(t_dupstruct *f, char *cmd, char stac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("\x1b[2J");
	if (stac == 'a')
		ft_printf("\033[1;33msa\033[0m\n");
	else if (stac == 'b')
		ft_printf("\033[1;33sb\033[0m\n");
	else
		ft_printf("\033[1;33m%s\033[0m\n", cmd);
	ft_printf("\033[1;35mSTAC_A	STAC_B\033[0m\n");
	while (i < f->len_stac_a || j < f->len_stac_b)
	{
		(i < f->len_stac_a) ? ft_printf("\033""[1;36m%d\033[0m", f->stac_a[i])
		: write(1, "", 0);
		ft_printf("	");
		(j < f->len_stac_b) ? ft_printf("\033[1;36m%d\033[0m\n", f->stac_b[j])
		: write(1, "\n", 1);
		j++;
		i++;
	}
	usleep(200 * 1000);
}

int		ft_check_param(t_dupstruct *f, char *cmd, char stac)
{
	if ((f->len_stac_b + f->len_stac_a) > 40)
	{
		write_highstac(f, cmd, stac);
		return (0);
	}
	if (f->c == 1)
	{
		ft_print_color(f, cmd, stac);
		return (0);
	}
	return (1);
}

void	ft_print_stac(t_dupstruct *f, char *cmd, char stac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!ft_check_param(f, cmd, stac))
		return ;
	ft_clear_win(cmd, stac);
	while (i < f->len_stac_a || j < f->len_stac_b)
	{
		(i < f->len_stac_a) ? ft_printf("%d", f->stac_a[i])
		: write(1, "", 0);
		(j < f->len_stac_b) ? ft_printf("	%d\n", f->stac_b[j])
		: write(1, "\n", 1);
		i++;
		j++;
	}
	usleep(200 * 1000);
}
