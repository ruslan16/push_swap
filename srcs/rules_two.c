#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_reverse_rotate_a(t_dupstruct *f, int button)
{
	int tmp;
	int len;

	tmp = f->stac_a[f->len_stac_a - 1];
	len = f->len_stac_a - 1;
	while (len > 0)
	{
		f->stac_a[len] = f->stac_a[len - 1];
		len--;
	}
	f->stac_a[0] = tmp;
	if (button != 1)
		ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_dupstruct *f, int button)
{
	int tmp;
	int len;

	tmp = f->stac_b[f->len_stac_b - 1];
	len = f->len_stac_b - 1;
	while (len > 0)
	{
		f->stac_b[len] = f->stac_b[len - 1];
		len--;
	}
	f->stac_b[0] = tmp;
	if (button != 1)
		ft_printf("rrb\n");
}

void	ft_rotate_a(t_dupstruct *f, int button)
{
	int tmp;
	int i;
	int len;

	i = 0;
	tmp = f->stac_a[0];
	len = f->len_stac_a - 1;
	while (i < len)
	{
		f->stac_a[i] = f->stac_a[i + 1];
		i++;
	}
	f->stac_a[len] = tmp;
	if (button != 1)
		ft_printf("ra\n");
}

void	ft_rotate_b(t_dupstruct *f, int button)
{
	int tmp;
	int i;
	int len;

	i = 0;
	tmp = f->stac_b[0];
	len = f->len_stac_b - 1;
	while (i < len)
	{
		f->stac_b[i] = f->stac_b[i + 1];
		i++;
	}
	f->stac_b[len] = tmp;
	if (button != 1)
		ft_printf("rb\n");
}

