/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:10:28 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 20:12:37 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

int		ft_check_bonus(char *str, t_struct *f)
{
	if (str[0] == '-')
	{
		if (str[1] == 'v')
			f->v = 1;
		else
			return (0);
	}
	else
		return (0);
	if (f->v == 1 && str[2] == 'c')
		f->c = 1;
	else if (f->v == 1 && str[2] != '\0')
		return (0);
	if (f->c == 1 && f->v == 1 && str[3] != '\0')
		return (0);
	return (1);
}

int		if_not_double(t_struct *f)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < f->len_stac_a)
	{
		while (j < f->len_stac_a)
		{
			if (f->stac_a[i] == f->stac_a[j])
				count++;
			if (count > 1)
				return (0);
			j++;
		}
		j = 0;
		count = 0;
		i++;
	}
	return (1);
}

int		pars_two(char *str, t_struct *f, int i)
{
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]))
			i++;
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		if (!ft_check_max(&str[i]))
			return (0);
		f->stac_a[f->i] = ft_atoi(&str[i]);
		f->i++;
		f->len_stac_a++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (i != 0 && str[i - 1] != ' ')
				return (0);
			if (ft_isdigit(str[i + 1]))
				i++;
			else
				return (0);
		}
		while (ft_isdigit(str[i]))
			i++;
	}
	return (1);
}

int		parsing(char *str[], t_struct *f, int button)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (i == 1 && ft_check_bonus(str[1], f))
			i++;
		if (!pars_two(str[i], f, 0))
		{
			ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
			return (0);
		}
		i++;
	}
	if (!if_not_double(f))
	{
		ft_putstr_fd("\033[1;31mError\033[0m\n", 2);
		return (0);
	}
	if (button == 0)
		ft_sort(f);
	else
		ft_read_command(f);
	return (1);
}
