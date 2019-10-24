/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:44:36 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/24 22:05:28 by jvaquer          ###   ########.fr       */
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
int			ft_strlen_nb(long nb, int base);

#endif