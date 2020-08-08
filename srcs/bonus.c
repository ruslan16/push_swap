#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void 	ft_print_stac(t_dupstruct *f, char *cmd, char stac)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr("\x1b[2J");
	if (stac == 'a')
		ft_printf("sa\n");
	else if (stac == 'b')
		ft_printf("sb\n");
	else
		ft_printf("%s\n", cmd);
	ft_printf("\n\n");
	ft_printf("STAC_A	STAC_B\n\n");
	while (i < f->len_stac_a || j < f->len_stac_b)
	{
		(i < f->len_stac_a) ? ft_printf("%d", f->stac_a[i]) : write(1, "", 0);
		(j < f->len_stac_b) ? ft_printf("	%d\n", f->stac_b[j]) : write(2, "\n", 1);
		j++;
		i++;
	}
	sleep(1);
}