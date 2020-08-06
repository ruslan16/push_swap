#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void 	ft_check_sort(t_struct *f)
{
	while (!ft_is_sorted(f->stac_a, f->len_stac_a))
	{

	}
}

void	bezerostruct(t_struct *f, int size_stac)
{
	if (!(f->stac_a = (int *)malloc(sizeof(int) * (size_stac - 1))))
		return ;
	if (!(f->stac_b = (int *)malloc(sizeof(int) * (size_stac - 1))))
		return ;
	f->i = 0;
	f->len_stac_a = 0;
	f->len_stac_b = 0;
}

int 	main(int argc, char *argv[])
{
	t_struct *f;
	int size_stac;

	size_stac = ft_size_stac(argv, argc);
	if (!(f = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	bezerostruct(f, size_stac);
	if (argc >= 2)
		parsing(argv, f, 1);
	free(f->stac_a);
	free(f->stac_b);
	free(f);
	return(0);
}