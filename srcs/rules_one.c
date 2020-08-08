#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_swapab(t_dupstruct *f, char name_stac, int button)
{
	int tmp;

	if (name_stac == 'a')
	{
		if (f->len_stac_a > 1)
		{
			tmp = f->stac_a[0];
			f->stac_a[0] = f->stac_a[1];
			f->stac_a[1] = tmp;
		}
	}
	else if (name_stac == 'b')
	{
		if (f->len_stac_b > 1)
		{
			tmp = f->stac_b[0];
			f->stac_b[0] = f->stac_b[1];
			f->stac_b[1] = tmp;
		}
	}
	if (button != 1)
		(name_stac == 'a') ? ft_printf("sa\n") : ft_printf("sb\n");
	(f->v == 1) ? ft_print_stac(f, "s", name_stac) : ft_printf("");
}

void	ft_push_a(t_dupstruct *f, int button)
{
	int len_a;
	int len_b;
	int i;

	len_b = f->len_stac_b - 1;
	len_a = f->len_stac_a - 1;
	i = -1;
	if (f->len_stac_b > 0)
	{
		while (len_a >= 0)
		{
			f->stac_a[len_a + 1] = f->stac_a[len_a];
			len_a--;
		}
		f->stac_a[0] = f->stac_b[0];
		f->len_stac_a++;
		while (i++ < len_b)
			f->stac_b[i] = f->stac_b[i + 1];
		f->len_stac_b--;
		(button == 0) ? ft_printf("pa\n") : ft_printf("");
	}
	(f->v == 1) ? ft_print_stac(f, "pa", 'n') : ft_printf("");
}

void	ft_push_b(t_dupstruct *f, int button)
{
	int len_a;
	int len_b;
	int i;

	len_b = f->len_stac_b - 1;
	len_a = f->len_stac_a - 1;
	i = -1;
	if (f->len_stac_a > 0)
	{
		while (len_b >= 0)
		{
			f->stac_b[len_b + 1] = f->stac_b[len_b];
			len_b--;
		}
		f->stac_b[0] = f->stac_a[0];
		f->len_stac_b++;
		while (i++ < len_a)
			f->stac_a[i] = f->stac_a[i + 1];
		f->len_stac_a--;
		(button == 0) ? ft_printf("pb\n") : ft_printf("");
	}
	(f->v == 1) ? ft_print_stac(f, "pb", 'n') : ft_printf("");
}
