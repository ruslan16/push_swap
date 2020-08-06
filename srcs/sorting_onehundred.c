#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void 	ft_push_to_a(t_dupstruct *f, int index_max, int j)
{
	while (f->len_stac_b != 0)
	{
		index_max = ft_index_highel(f->stac_b, f->len_stac_b);
		if (index_max > f->len_stac_b / 2)
		{
			while (f->len_stac_b - index_max != 0)
			{
				ft_reverse_rotate_b(f, 0);
				index_max++;
			}
		}
		else
		{
			while (index_max != 0)
			{
				ft_rotate_b(f, 0);
				index_max--;
			}
		}
		ft_push_a(f);
	}
}

void 	find_element(t_dupstruct *f, int i, int j)
{
	if (i < j)
	{
		while (i > 0)
		{
			ft_rotate_a(f, 0);
			i--;
		}
	}
	else
	{
		while (j > 0)
		{
			ft_reverse_rotate_a(f, 0);
			j--;
		}
	}
	if (f->stac_a[0] > ft_highelement(f->stac_b, f->len_stac_b))
	{
		while (ft_index_lowel(f->stac_b, f->len_stac_b) != 0)
			ft_rotate_b(f, 0);
	}
	ft_push_b(f);
}

void 	ft_fill_stac(t_dupstruct *f, int i, int j)
{
	while (j++ < (f->len_stac_a / 5))
	{
		f->stac_two[j] = f->sorted_stac[i];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / 5))
	{
		f->stac_three[j] = f->sorted_stac[i -1];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / 5))
	{
		f->stac_four[j] = f->sorted_stac[i - 2];
		i++;
	}
	j = -1;
	while (j++ < (f->len_stac_a / 5))
	{
		f->stac_five[j] = f->sorted_stac[i - 3];
		i++;
	}
}

void 	ft_sort_onehundred(t_dupstruct *f)
{
	int i;

	f->sorted_stac = ft_sorted(f->stac_a, f->len_stac_a);
	i = 0;
	f->stac_one = ft_memalloc(f->len_stac_a / 5);
	f->stac_two = ft_memalloc(f->len_stac_a / 5);
	f->stac_three = ft_memalloc(f->len_stac_a / 5);
	f->stac_four = ft_memalloc(f->len_stac_a / 5);
	f->stac_five = ft_memalloc(f->len_stac_a - (f->len_stac_a / 5) * 4);
	i = -1;
	while (i++ < (f->len_stac_a / 5))
		f->stac_one[i] = f->sorted_stac[i];
	ft_fill_stac(f, i -1, -1);
	work_with_onestac(f, 0, 0, f->len_stac_a / 5);
	ft_push_to_a(f, 0, 0);
	free(f->stac_one);
	free(f->stac_two);
	free(f->stac_three);
	free(f->stac_four);
	free(f->stac_five);
	free(f->sorted_stac);
}
