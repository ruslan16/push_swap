#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_sort_two(t_dupstruct *f)
{
	if (f->stac_a[0] > f->stac_a[1])
		ft_swapab(f, 'a' ,0);
}

void 	ft_sort_three_d(int *stac, t_dupstruct *f, char name_stac)
{
	if (stac[0] == ft_lowelement(stac, 3) &&
		stac[1] == ft_highelement(stac, 3))
	{
		ft_swapab(f, name_stac, 0);
		if (name_stac == 'a')
			ft_rotate_a(f, 0);
		else if (name_stac == 'b')
			ft_rotate_b(f, 0);
	}
	else if (stac[1] == ft_highelement(stac, 3) &&
		stac[2] == ft_lowelement(stac, 3))
	{
		if (name_stac == 'a')
			ft_reverse_rotate_a(f, 0);
		else if (name_stac == 'b')
			ft_reverse_rotate_b(f, 0);
	}
}

void 	ft_sort_three(int *stac, t_dupstruct *f, char name_stac)
{
	if (stac[2] == ft_highelement(stac, 3) &&
		stac[1] == ft_lowelement(stac, 3))
		ft_swapab(f, name_stac, 0);
	else if ((stac[0] == ft_highelement(stac, 3)) &&
		(stac[2] == ft_lowelement(stac, 3)))
	{
		ft_swapab(f, name_stac, 0);
		if (name_stac == 'a')
			ft_reverse_rotate_a(f, 0);
		else if (name_stac == 'b')
			ft_reverse_rotate_b(f, 0);
	}
	else if (stac[0] == ft_highelement(stac, 3) &&
		stac[1] == ft_lowelement(stac, 3))
	{
		if (name_stac == 'a')
			ft_rotate_a(f, 0);
		else if (name_stac == 'b')
			ft_rotate_b(f, 0);
	}
	ft_sort_three_d(stac, f, name_stac);
}
