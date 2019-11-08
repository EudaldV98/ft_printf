/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:54:43 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/08 18:14:46 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define CAP "0123456789ABCDEF"
# define MIN "0123456789abcdef"
# define NUMB 0
# define ADDR 1
# define CHAR 2
# define PADD 3

typedef struct	s_printf
{
	int		fl_min;
	int		space_b;
	int		space_a;
	int		fl_z;
	int		fl_z_before;
	int		fl_star;
	int		width;
	int		conv;
	int		size;
	int		fl_point;
	int		pcent;
	int		flag;
}				t_printf;

void		ft_specifier_s(va_list arg, int *res, t_printf *t_flag);
void		ft_specifier_c(va_list arg, int *res, t_printf *t_flag);
int			ft_printf(const char *format, ...);
t_printf	*ft_init_struct(void);
int			ft_is_flag(char c, t_printf *t_flag, int *i);
t_printf	*ft_parse_conv(int *i, const char *str, va_list arg, int *res);
void		ft_update_value(t_printf *t_flag, int neg, int type);
void		ft_handle_exceptions(t_printf *t_flag, int type);
void		ft_out(char *str, int *res, t_printf *t_flag);
void		ft_space(int nb, int cas, int *res, t_printf *t_flag);
void		ft_handle_spaces(int *res, t_printf *t_flag, int size, int neg);

void		ft_specifier_c(va_list arg, int *res, t_printf *t_flag);
void		ft_specifier_d(va_list arg, int *res, t_printf *t_flag);
void		ft_specifier_s(va_list arg, int *res, t_printf *t_flag);
void		ft_specifier_u(va_list arg, int *res, t_printf *t_flag);
void		ft_specifier_p(va_list arg, int *res, t_printf *t_flag);
void		ft_specifier_x(va_list arg, int *res, t_printf *t_flag);

void		ft_flag_zero(int *res, t_printf *t_flag, int *i);
void		ft_flag_minus(int *res, t_printf *t_flag, char *str, int *i);
void		ft_flag_point(int *res, t_printf *t_flag, char *str, int *i);
void		ft_flag_ptr(va_list arg, int *res, t_printf *t_flag);
#endif