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
	d->vb = f->vb;
}

void	bezerostruct(t_struct *f, int size_stac)
{
	f->stac_a = ft_memalloc(size_stac - 1);
	f->stac_b = ft_memalloc(size_stac - 1);
	f->i = 0;
	f->len_stac_a = 0;
	f->len_stac_b = 0;
	f->v = 0;
	f->c = 0;
	f->vb = 0;
}

int		main(int argc, char *argv[])
{
	t_struct *f;
	int size_stac;

	size_stac = ft_size_stac(argv, argc);
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	bezerostruct(f, size_stac);
	if (argc >= 2)
		parsing(argv, f, 0);
	free(f->stac_a);
	free(f->stac_b);
	free(f);
	return(0);
}