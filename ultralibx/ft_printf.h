#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <stdlib.h>

typedef	struct	s_printf
{
	int			wh;
	int			prec;
	unsigned	is_left:1;
	unsigned	is_zero:1;
	unsigned	is_prec:1;
	unsigned	rec_prec:1;
	unsigned	to_up:1;
	unsigned	v_min:1;
	unsigned	count;
}				t_printf;

void			ft_putnbr_fd_count(t_printf *list, long int n, int fd);
void			ft_putnbr_u_fd_count(t_printf *list, unsigned int n, int fd);
void			ft_putchar_fd_count(t_printf *list, char c, int fd);
int				ft_printf(const char *format, ...);
int				parser_prtf(char **str, va_list *name);
void			while_c(t_printf *list, char c, int i);
void			d_isprec(t_printf *list, int value);
int				lennbr(long int n);
int				is_flag(char **str, t_printf *params);
int				is_star(char **str, va_list *arg, t_printf *params);
int				is_digit(char **str, t_printf *params);
int				is_type(char **str, int *cout, va_list *arg, t_printf *params);
int				len_value(t_printf *list, long int value);
void			d_isleft(t_printf *list, int value);
void			d_isleft_2(t_printf *list, int value);
void			ft_write_d(t_printf *list, int value);
void			ft_write_d_2(t_printf *list, int value);
void			for_min_diszero(t_printf *list, int value, int tmp, int *c);
void			for_diszero(t_printf *list, int value, int tmp, int c);
void			printf_value(t_printf *list, int value);
int				len_u_value(t_printf *list, unsigned int value);
void			u_isleft(t_printf *list, unsigned int value);
void			u_iszero(t_printf *list, unsigned int value);
void			u_isprec(t_printf *list, unsigned int value);
void			ft_write_u(t_printf *list, unsigned int value);
int				u_lennbr(unsigned int n);
void			printf_u_value(t_printf *list, unsigned int value);
void			for_uiszero(t_printf *list, unsigned int value, int tmp, \
unsigned int c);
void			for_min_uiszero(t_printf *list, unsigned int value, int tmp,\
unsigned int *c);
void			u_isleft_ext(t_printf *list, unsigned int value);
void			x_isleft(t_printf *list, unsigned int value);
void			x_iszero(t_printf *list, unsigned int value);
void			x_isprec(t_printf *list, unsigned int value);
int				len_x_value(t_printf *list, unsigned int value);
void			ft_write_x(t_printf *list, unsigned int value);
void			printf_x_value(t_printf *list, unsigned int value);
void			print_hex(unsigned int value, t_printf *list);
int				len_hex(unsigned int value);
void			for_xiszero(t_printf *list, unsigned int value, int \
tmp, unsigned int c);
void			for_min_xiszero(t_printf *list, unsigned int value, int tmp,\
unsigned int *c);
void			print_hep(t_printf *list, long int value);
int				len_hep(long int value);
void			for_piszero(t_printf *list, long int value, long int tmp, \
long int c);
void			for_min_piszero(t_printf *list, long int value, long int tmp,\
long int *c);
void			printf_p_value(t_printf *list, long int value);
void			p_isleft(t_printf *list, long int value);
void			p_iszero(t_printf *list, long int value);
void			p_isprec(t_printf *list, long int value);
int				len_hep(long int value);
void			ft_write_p(t_printf *list, long int value);
void			printf_p_value_2(t_printf *list, long int value, int b);
int				ft_put_percent(t_printf *list);
int				ft_put_c(t_printf *list, va_list *name);
int				ft_put_d(t_printf *list, va_list *name);
int				ft_put_p(t_printf *list, va_list *name);
int				ft_put_s(t_printf *list, va_list *name);
int				ft_put_u(t_printf *list, va_list *name);
int				ft_put_x(t_printf *list, va_list *name);

#endif
