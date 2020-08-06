#include "../libft/includes/ft_printf.h"
#include "../includes/push_swap.h"

int 	if_not_double(t_struct *f)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (i < f->len_stac_a)
	{
		while (j < f->len_stac_a)
		{
			if (f->stac_a[i] == f->stac_a[j])
				count++;
			if (count > 1)
				return (0);
			j++;
		}
		j = 0;
		count = 0;
		i++;
	}
	return (1);
}

int 	pars_two(char *str, t_struct *f, int i)
{
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]))
			i++;
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		f->stac_a[f->i] = ft_atoi(&str[i]);
		f->i++;
		f->len_stac_a++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (ft_isdigit(str[i + 1]))
				i++;
			else
				return (0);
		}
		while (ft_isdigit(str[i]))
			i++;
	}
	return (1);
}

int 	parsing(char *str[], t_struct *f, int button)
{
	int i;

	i = 1;
	while (str[i])
	{
		if(!pars_two(str[i], f, 0))
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	if (!if_not_double(f))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (button == 0)
		ft_sort(f);
	else
		ft_check_sort(f);
	return (1);
}