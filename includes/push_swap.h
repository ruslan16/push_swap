
#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H
# include <unistd.h>
# include <time.h>

typedef struct	s_struct
{
	int			*stac_a;
	int			i;
	int			*stac_b;
	int			len_stac_a;
	int			len_stac_b;
	int 		v;
	int 		c;
}				t_struct;

typedef struct	s_dupstruct
{
	int			len_stac_a;
	int			len_stac_b;
	int 		c;
	int			v;
	int			*stac_a;
	int			*stac_b;
	int 		*stac_one;
	int 		*stac_two;
	int 		*stac_three;
	int 		*stac_four;
	int 		*stac_five;
	int 		*stac_six;
	int 		*stac_seven;
	int 		*stac_eight;
	int 		*stac_nine;
	int 		*stac_ten;
	int 		*stac_eleven;
	int 		*sorted_stac;
}				t_dupstruct;

int		parsing(char *str[], t_struct *f, int button);
void	ft_sort(t_struct *f);
void	bezerostructdup(t_dupstruct *d, t_struct *f);
int 	ft_check_sort(t_dupstruct *f);

void	ft_swapab(t_dupstruct *f, char name_stac, int button);
void	ft_ss(t_dupstruct *f, int button);
void	ft_push_a(t_dupstruct *f, int button);
void	ft_push_b(t_dupstruct *f, int button);
void	ft_rotate_a(t_dupstruct *f, int button);
void	ft_rotate_b(t_dupstruct *f, int button);
void	ft_rotate_ab(t_dupstruct *f, int button);
void	ft_reverse_rotate_a(t_dupstruct *f, int button);
void	ft_reverse_rotate_b(t_dupstruct *f, int button);
void	ft_reverse_rotate_ab(t_dupstruct *f, int button);

void	ft_sort_two(t_dupstruct *f);
void 	ft_sort_three(int *stac, t_dupstruct *f, char name_stac);
void 	ft_sort_three_d(int *stac, t_dupstruct *f, char name_stac);
void 	ft_sort_four(t_dupstruct *f);
void 	ft_sort_five(t_dupstruct *f);
void 	ft_sort_five_d(t_dupstruct *f);
void 	ft_sort_onehundred(t_dupstruct *f);
void 	work_with_onestac(t_dupstruct *f, int count_stacs, int j, int size_stacs);
void 	work_with_sixstac(t_dupstruct *f, int i, int j, int size_stacs);
void 	work_with_elevenstac(t_dupstruct *f, int i, int j, int size_stacs);
void 	find_element(t_dupstruct *f, int i, int j);
void 	ft_fill_stac(t_dupstruct *f, int i, int j, int count_stac);
void 	ft_fill_stac_d(t_dupstruct *f, int i, int j, int count_stac);
void 	ft_fill_stac_t(t_dupstruct *f, int i, int j, int count_stac);
void 	ft_fill_stac_f(t_dupstruct *f, int i, int j, int count_stac);
void 	ft_sort_fivehundred(t_dupstruct *f);
void 	ft_push_to_a(t_dupstruct *f, int index_max);

int 	ft_size_stac(char *str[], int size);
int		ft_highelement(int *num, int len);
int		ft_lowelement(int *num, int len);
int 	ft_index_lowel(int *num, int len);
int 	ft_index_highel(int *num, int len);
int 	ft_is_sorted(int *num, int len);
int 	ft_intchr(int num, int *stac, int len_stac);
int 	*ft_sorted(int *num, int len);
int 	*ft_intdup(int *num, int *num1, int len);
void 	ft_clear_stacs(t_dupstruct *f, int count_stacs);
int 	ft_check_max(char *str);

int 	ft_check_command(char *cmd, t_dupstruct *f);
void 	ft_read_command(t_struct *f);
int		ft_check_sort(t_dupstruct *f);

int 	ft_check_bonus(char *str, t_struct *f);
void 	ft_print_stac(t_dupstruct *f, char *cmd, char stac);
void	write_highstac(t_dupstruct *f, char *cmd, char stac);

#endif //PUSH_SWAP_PUSH_SWAP_H
