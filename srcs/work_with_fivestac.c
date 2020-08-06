#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void 	work_with_fivestac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_five, size_stacs))
				break;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_five, size_stacs))
				break;
			j--;
		}
		//ft_printf("i - %d\nj - %d\n", i, j);
		find_element(f, i, f->len_stac_a - j);
	}
}

void 	work_with_fourstac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_four, size_stacs))
				break;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_four, size_stacs))
				break;
			j--;
		}
		//ft_printf("i - %d\nj - %d\n", i, j);
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_fivestac(f, 0, 0, size_stacs);
}

void 	work_with_threestac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_three, size_stacs))
				break;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_three, size_stacs))
				break;
			j--;
		}
		//ft_printf("i - %d\nj - %d\n", i, j);
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_fourstac(f, 0, 0, size_stacs);
}

void 	work_with_twostac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_two, size_stacs))
				break;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_two, size_stacs))
				break;
			j--;
		}
		//ft_printf("i - %d\nj - %d\n", i, j);
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_threestac(f, 0, 0, size_stacs);
}

void 	work_with_onestac(t_dupstruct *f, int i, int j, int size_stacs)
{
	int count;

	count = 0;
	while (count++ != size_stacs)
	{
		j = f->len_stac_a - 1;
		i = 0;
		while (i < (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[i], f->stac_one, size_stacs))
				break;
			i++;
		}
		while (j >= (f->len_stac_a / 2))
		{
			if (ft_intchr(f->stac_a[j], f->stac_one, size_stacs))
				break;
			j--;
		}
		//ft_printf("i - %d\nj - %d\n", i, j);
		find_element(f, i, f->len_stac_a - j);
	}
	work_with_twostac(f, 0, 0, size_stacs);
}

