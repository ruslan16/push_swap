#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void 	work_with_elevenstac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_eleven, f->len_stac_a))
				break;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_eleven, f->len_stac_a))
				break;
			j--;
		}
		find_element(f, i, f->len_stac_a - j);
	}
}

void 	ft_create_stacs(t_dupstruct *f, int size_stacs)
{
	int i;

	i = -1;
	f->stac_one = ft_memalloc(size_stacs);
	f->stac_two = ft_memalloc(size_stacs);
	f->stac_three = ft_memalloc(size_stacs);
	f->stac_four = ft_memalloc(size_stacs);
	f->stac_five = ft_memalloc(size_stacs);
	f->stac_six = ft_memalloc(size_stacs);
	f->stac_seven = ft_memalloc(size_stacs);
	f->stac_eight = ft_memalloc(size_stacs);
	f->stac_nine = ft_memalloc(size_stacs);
	f->stac_ten = ft_memalloc(size_stacs);
	f->stac_eleven = ft_memalloc(f->len_stac_a - (size_stacs * 10));
	while (i++ < size_stacs)
		f->stac_one[i] = f->sorted_stac[i];
	ft_fill_stac(f, i, -1, 11);
}

void 	ft_sort_fivehundred(t_dupstruct *f)
{
	f->sorted_stac = ft_sorted(f->stac_a, f->len_stac_a);
	ft_create_stacs(f, f->len_stac_a / 11);
	work_with_onestac(f, 11, 0, f->len_stac_a / 11);
	ft_push_to_a(f, 0);
	ft_clear_stacs(f, 11);
}