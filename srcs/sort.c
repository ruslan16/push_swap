#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_algo(t_dupstruct *f)
{
	if (ft_is_sorted(f->stac_a, f->len_stac_a))
		return ;
	else if (f->len_stac_a == 2)
		ft_sort_two(f);
	else if (f->len_stac_a == 3)
		ft_sort_three(f->stac_a, f, 'a');
	else if (f->len_stac_a == 4)
		ft_sort_four(f);
	else if (f->len_stac_a == 5)
		ft_sort_five(f);
	else if (f->len_stac_a > 5 && f->len_stac_a <= 100)
		ft_sort_onehundred(f);
	else if (f->len_stac_a >= 101)
		ft_sort_fivehundred(f);
}

void	ft_sort(t_struct *f)
{
	t_dupstruct *d;

	if (ft_is_sorted(f->stac_a, f->len_stac_a))
		return ;
	if (!(d = (t_dupstruct*)malloc(sizeof(t_dupstruct))))
		return ;
	bezerostructdup(d, f);
	ft_algo(d);
	free(d->stac_a);
	free(d->stac_b);
	free(d);
}