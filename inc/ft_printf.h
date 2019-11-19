/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:17:03 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 16:48:36 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define UMAX 4294967295

typedef struct	s_count
{
	int				i;
	int				len;
	int				space;
	long			zero;
	int				check;
	char			*str;
}				t_count;

int				ft_strlen_nb(long nb, int base);
t_count			ft_init_count(t_count init, int k);
int				ft_convertible(char c);
void			ft_strdel(char **s);

t_count			ft_specifier_d(va_list aux, t_count cmp);
t_count			ft_specifier_u(va_list aux, t_count cmp);
t_count			ft_specifier_c(va_list aux, t_count cmp);
t_count			ft_specifier_s(va_list aux, t_count cmp);
t_count			ft_specifier_mod(va_list au, t_count cmp);
t_count			ft_specifier_xp(va_list aux, t_count cmp, char c);
t_count			ft_specifier_p(t_count cmp, long long nb);
t_count			ft_specifier_x(t_count cmp, long long nb, char c);

t_count			ft_flag_z(va_list aux, t_count cmp, const char *s);
t_count			ft_flag_p(va_list aux, t_count cmp, const char *s);
t_count			ft_flag_m(va_list aux, t_count cmp, char *s);
t_count			ft_flag_nb(va_list aux, t_count cmp, char *s);
t_count			ft_flag_ptr(va_list aux, const char *s, t_count cmp);
t_count			ft_flags(va_list aux, t_count cmp, char c, char *s);
t_count			ft_switch_flag(va_list aux, t_count cmp, const char *s);

t_count			ft_print_front_flag(t_count cmp, int neg, char *s);
t_count			ft_print_back_flag(t_count cmp, int neg);
t_count			ft_print_arg(t_count cmp, char *s);
t_count			ft_check(va_list aux, const char *s, t_count cmp);
int				ft_printf(const char *str, ...);

t_count			ft_check_null_str(t_count cmp, char *s);
t_count			ft_except_p(t_count cmp, char *s);
t_count			ft_reduc_str(t_count cmp, char *s);

#endif
