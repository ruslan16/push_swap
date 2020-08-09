/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_forchecker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:09:50 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:51:19 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

int		ft_check_sort(t_dupstruct *f)
{
	char	cmd[4];
	char	c;
	int		i;
	int		j;

	ft_bzero(cmd, sizeof(char) * 4);
	i = 0;
	while (read(0, &c, 1) > 0)
	{
		if (c == '\n')
		{
			j = ft_check_command(cmd, f);
			return ((j == -1) ? -1 : 1);
		}
		cmd[i] = c;
		i++;
		cmd[i] = '\0';
	}
	return (0);
}

void	ft_read_command(t_struct *f)
{
	int			res;
	t_dupstruct	*d;

	res = 5;
	if (!(d = (t_dupstruct*)malloc(sizeof(t_dupstruct))))
		return ;
	bezerostructdup(d, f);
	while (res != 0)
	{
		res = ft_check_sort(d);
		if (res == -1)
		{
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
			break ;
		}
	}
	if ((!ft_is_sorted(d->stac_a, d->len_stac_a) && res != -1)
	|| (d->len_stac_b != 0 && res != -1))
		ft_printf("\033[1;31mKO\033[0m\n");
	else if (ft_is_sorted(d->stac_a, d->len_stac_a)
	&& res != -1 && d->len_stac_b == 0)
		ft_printf("\033[1;32mOK\033[0m\n");
	free(d->stac_a);
	free(d->stac_b);
	free(d);
}

int		ft_check_command_d(char *cmd, t_dupstruct *f)
{
	if (ft_strequ(cmd, "rrr") == 1)
		ft_reverse_rotate_ab(f, 1);
	else if (ft_strequ(cmd, "pb") == 1)
		ft_push_b(f, 1);
	else if (ft_strequ(cmd, "pa") == 1)
		ft_push_a(f, 1);
	else if (ft_strequ(cmd, ""))
		return (1);
	else
		return (-1);
	return (1);
}

int		ft_check_command(char *cmd, t_dupstruct *f)
{
	if (ft_strequ(cmd, "sa") == 1)
		ft_swapab(f, 'a', 1);
	else if (ft_strequ(cmd, "sb") == 1)
		ft_swapab(f, 'b', 1);
	else if (ft_strequ(cmd, "ss") == 1)
		ft_ss(f, 1);
	else if (ft_strequ(cmd, "ra") == 1)
		ft_rotate_a(f, 1);
	else if (ft_strequ(cmd, "rb") == 1)
		ft_rotate_b(f, 1);
	else if (ft_strequ(cmd, "rr") == 1)
		ft_rotate_ab(f, 1);
	else if (ft_strequ(cmd, "rra") == 1)
		ft_reverse_rotate_a(f, 1);
	else if (ft_strequ(cmd, "rrb") == 1)
		ft_reverse_rotate_b(f, 1);
	else if (ft_check_command_d(cmd, f) != 1)
		return (-1);
	return (1);
}
