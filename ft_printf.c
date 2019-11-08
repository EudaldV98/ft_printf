/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:52:49 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/06 11:42:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	int			res;
	t_printf	*t_flag;

	i = 0;
	res = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			t_flag = ft_parse_conv(&i, format, arg, &res);
			i--;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
		}
		i++;
	}
	va_end(arg);
	return (res);
}
