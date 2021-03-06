/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sirvin <sirvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:10:19 by sirvin            #+#    #+#             */
/*   Updated: 2020/08/09 22:13:34 by sirvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	bezerostructdup(t_dupstruct *d, t_struct *f)
{
	d->stac_a = ft_memalloc(f->len_stac_a);
	d->stac_a = ft_intdup(d->stac_a, f->stac_a, f->len_stac_a);
	d->stac_b = ft_memalloc(f->len_stac_a);
	d->len_stac_a = f->len_stac_a;
	d->len_stac_b = f->len_stac_b;
	d->v = f->v;
	d->c = f->c;
	if (d->v == 1)
		ft_print_stac(d, "", 'n');
}

void	bezerostruct(t_struct *f, int size_stac)
{
	f->stac_a = ft_memalloc(size_stac - 1);
	f->stac_b = ft_memalloc(size_stac - 1);
	f->i = 0;
	f->v = 0;
	f->c = 0;
	f->len_stac_a = 0;
	f->len_stac_b = 0;
}

int		main(int argc, char *argv[])
{
	t_struct	*f;
	int			size_stac;

	size_stac = ft_size_stac(argv, argc);
	if (ft_strequ(argv[1], ""))
		return (0);
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	bezerostruct(f, size_stac);
	if (argc >= 2)
		parsing(argv, f, 1);
	free(f->stac_a);
	free(f->stac_b);
	free(f);
	return (0);
}
