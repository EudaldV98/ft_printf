/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:44:36 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/23 17:55:23 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

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
#endif