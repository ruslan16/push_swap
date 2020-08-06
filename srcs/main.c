#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	bezerostructdup(t_dupstruct *d, t_struct *f)
{
	if (!(d->stac_a = (int *)malloc(sizeof(int) * (f->len_stac_a))))
		return ;
	d->stac_a = f->stac_a;
	if (!(d->stac_b = (int *)malloc(sizeof(int) * (f->len_stac_a))))
		return ;
	d->i = 0;
	d->len_stac_a = f->len_stac_a;
	d->len_stac_b = f->len_stac_b;
}

void	bezerostruct(t_struct *f, int argc)
{
	if (!(f->stac_a = (int *)malloc(sizeof(int) * (argc - 1))))
		return ;
	if (!(f->stac_b = (int *)malloc(sizeof(int) * (argc - 1))))
		return ;
	f->i = 0;
	f->len_stac_a = 0;
	f->len_stac_b = 0;
}

int		main(int argc, char *argv[])
{
	t_struct *f;
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	bezerostruct(f, argc);
	if (argc >= 2)
	{
		if (!parsing(argv, f))
			return (0);
	}
	else if (argc < 2)
		ft_printf("Error\n");
	free(f->stac_a);
	free(f->stac_b);
	free(f);
	return(0);
}