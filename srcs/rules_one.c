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
}

void	ft_push_a(t_dupstruct *f)
{
	int len_a;
	int len_b;
	int i;

	len_b = f->len_stac_b - 1;
	len_a = f->len_stac_a - 1;
	i = 0;
	if (f->len_stac_b > 0)
	{
		while (len_a >= 0)
		{
			f->stac_a[len_a + 1] = f->stac_a[len_a];
			len_a--;
		}
		f->stac_a[0] = f->stac_b[0];
		f->len_stac_a++;
		while (i < len_b)
		{
			f->stac_b[i] = f->stac_b[i + 1];
			i++;
		}
		f->len_stac_b--;
		ft_printf("pa\n");
	}
}

void	ft_push_b(t_dupstruct *f)
{
	int len_a;
	int len_b;
	int i;

	len_b = f->len_stac_b - 1;
	len_a = f->len_stac_a - 1;
	i = 0;
	if (f->len_stac_a > 0)
	{
		while (len_b >= 0)
		{
			f->stac_b[len_b + 1] = f->stac_b[len_b];
			len_b--;
		}
		f->stac_b[0] = f->stac_a[0];
		f->len_stac_b++;
		while (i < len_a)
		{
			f->stac_a[i] = f->stac_a[i + 1];
			i++;
		}
		f->len_stac_a--;
		ft_printf("pb\n");
	}
}
