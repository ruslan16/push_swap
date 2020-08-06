#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

void	ft_ss(t_dupstruct *f)
{
	ft_swapab(f, 'a', 1);
	ft_swapab(f, 'b', 1);
	ft_printf("ss\n");
}

void	ft_rotate_ab(t_dupstruct *f)
{
	ft_rotate_a(f, 1);
	ft_rotate_b(f, 1);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_ab(t_dupstruct *f)
{
	ft_reverse_rotate_a(f, 1);
	ft_reverse_rotate_b(f, 1);
	ft_printf("rrr\n");
}
