/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:44:36 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/25 18:04:09 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define CAPS "0123456789ABCDEF"
# define MINU "0123456789abcdef"

typedef struct	s_struct
{
	int		i;
	int		len;
	int		space;
	int 	zero;
	char	*str;
}				t_struct;
int		ft_printf(const char *format, ...);

t_struct	ft_specifier_c(va_list arg, t_struct ret);
t_struct	ft_spcifier_d(va_list arg, t_struct ret);
t_struct	ft_specifier_s(va_list arg, t_struct ret);
t_struct	ft_specifier_u(va_list arg, t_struct ret);
t_struct	ft_specifier_hex(va_list arg, t_struct ret, char c);
t_struct	ft_specifier_flags(va_list arg, t_struct ret, char c, const char *s);
t_struct	ft_flag_pointer(va_list arg, const char *s, t_struct ret);
t_struct	ft_flag_point(va_list arg, t_struct ret, const char *s);
t_struct	ft_flag_minus(va_list arg, t_struct ret, const char *s);
t_struct	ft_print_flag(t_struct ret, int sign);
t_struct	ft_print_flag_back(t_struct ret, int sign);
int			ft_strlen_nb(long nb, int base);
int			ft_is_convert(char c);

#endif